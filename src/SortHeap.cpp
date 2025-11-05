//
// Created by Tatiana on 10/27/2025.
//
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
void siftDown (std::vector <Songs>&song, int root, int end) {
    //https://www.mygreatlearning.com/blog/heap-sort/

    while (true) {
        int left = 2 * root + 1;
        int right = 2* root + 2;
        int Largest = root;

        // Ensuring the left node is not greater than the 'end'
        if (left > end) {
            break;
        }

        //Checking if 'left' is hotter
        if (left <= end && hotter(song[left], song[Largest])){
            Largest = left;
        }

        //Checking if 'right' is hotter
        if (right <= end && hotter(song[right], song[Largest])) {
            Largest = right;
        }

        // If 'root' is still the largest.
        if (Largest == root) {
            return;
        }

        // Swap and continue Sift down
        std::swap(song[root], song[Largest]);
        root = Largest;
    }
}

void heapSort(std::vector<Songs>&song) {
    int n = song.size();
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



