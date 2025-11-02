//
// Created by Tatiana on 10/27/2025.
//
<<<<<<< HEAD
#include "../include/SortHeap.h"
#include <algorithm> // for std::swap
using namespace std;

// ___________________________________________________________
// Helper Function: Compare two Songs
// ___________________________________________________________
bool hotter (const Songs& a, const Songs& b) {
    return a.hotness > b.hotness;
};


//___________________________________________________________
// Helper Function : Sift down
//   Moves the value at the 'root' down
//   the heap until the heap property is restored.
// _________________________________________________________
void siftDown (std::vector <Songs>& songs, int root, int end) {

    while (true) {
        int left = 2 * root + 1;
        int right = 2* root + 2;
        int Largest = root;

        // Ensuring the left node is not greater than the 'end'
        if (left > end) {
            break;
        }

        //Checking if 'left' is hotter
        if (left <= end && hotter(songs[left], songs[Largest])){
            Largest = left;
        }

        //Checking if 'right' is hotter
        if (right <= end && hotter(songs[right], songs[Largest])) {
            Largest = right;
        }

        // If 'root' is still the largest.
        if (Largest == root) {
            return;
        }

        // Swap and continue Sift down
        std::swap(songs[root], songs[Largest]);
        root = Largest;
    }
}

void heapSortByHotness(vector <Songs>& song) {
    int n = (int)song.size();
    if (n <= 1) {
        return;
    }

    // Building Max Heap
    for (int start = (n - 2)/2 ; start >= 0; --start){
        siftDown(song, start, n-1);
    }

    //Sorting the array
    for (int end = n-1 ; end > 0; --end) {
        std::swap(song[0], song[end]);

        siftDown(song,0, end - 1);
    }

    // Revere so Hottest is at the top
    std::reverse(song.begin(), song.end());

};
=======

#include "../include/SortHeap.h"
#include <algorithm>
using namespace std;

void heapSortByHotness(vector <Songs> & a) {
    int n = a.size();
    if (n<= 1) {
        return;
    }

    //Initial Max-Heap
    for (int start = (n - 2)/2 ; start >= 0; --start) {
        siftDown(a, start, n-1);
    }

    //Sorting the array(retrieve max element)
    for (int end = n; end > 0; --end) {
        swap(a[0], a[end]);

        siftDown(a,0, end - 1);
        reverse(a.begin(), a.end()-1);
    }

};
bool hotter ( const Songs& a, const Songs& b) {
    return a.hotness > b.hotness;
};
void siftDown (vector <Songs>& a, int start, int end) {

    int root = start;
    while (true) {
        int left = 2 * root + 1;
        int right = 2* root + 2;

        // Ensuring the left node is not greater than the
        if ( left > end) {
            break;
        }

        int swapIdx = root;

        if (hotter(a[left], a[swapIdx])){
            swapIdx = left;
        }

        if ( right <= end && hotter(a[right], a[swapIdx])) {
            swapIdx = right;
        }

        if (swapIdx == root) {
            return;
        }
        swap(a[root], a[swapIdx]);
        root = swapIdx;
    }
}
>>>>>>> 88b68ad4da8bf6b3436464511d1fc670eb2e81ea

