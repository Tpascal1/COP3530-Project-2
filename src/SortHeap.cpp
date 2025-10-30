//
// Created by Tatiana on 10/27/2025.
//

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

