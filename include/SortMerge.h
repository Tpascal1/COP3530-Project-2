//
// Created by Deshna on 10/29/2025.
//

#ifndef SORTMERGE_H
#define SORTMERGE_H

#include <vector>
#include "Songs.h"
using namespace std ;

void mergeSort(vector<Songs>& songs);
void merge(vector<Songs>& songs, int left, int mid, int right);
void mergeSortHelper(vector<Songs>& songs, int left, int right);




#endif //SORTMERGE_H