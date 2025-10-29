//
// Created by Tatia on 10/27/2025.
//

#ifndef SORTHEAP_H
#define SORTHEAP_H

#include <vector>
#include "Songs.h"
using namespace std ;

void heapSortByHotness( vector <Songs> & a);
bool hotter ( const Songs& a, const Songs& b);
void siftDown (vector <Songs>& a, int start, int end);



#endif //SORTHEAP_H
