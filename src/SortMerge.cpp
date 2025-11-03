//
// Created by Deshna on 10/29/2025.
//

#include "../include/SortMerge.h"
#include <iostream>
#include <algorithm>
using namespace std;

//using this given in class for most of the code: https://www.onlinegdb.com/HJT6FfMlv
void merge(vector<Songs>& songs, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<Songs> L(n1);
  vector<Songs> R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = songs[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = songs[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) 
  {
    if (L[i].hotness >= R[j].hotness) 
    {
      songs[k] = L[i];
      i++;
    } 
    else 
    {
      songs[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) 
  {
    songs[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    songs[k] = R[j];
    j++;
    k++;
  }
}

void mergeSortHelper(vector<Songs>& songs, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(songs, left, mid);
        mergeSortHelper(songs, mid + 1, right);
        merge(songs, left, mid, right);
    }
}

void mergeSort(vector<Songs>& songs) {
    if (!songs.empty()) {
        mergeSortHelper(songs, 0, songs.size() - 1);
    }
}