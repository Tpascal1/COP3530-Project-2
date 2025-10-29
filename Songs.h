//
// Created by Tatiana on 10/23/2025.
//

#ifndef SONGS_H
#define SONGS_H


#include <iostream>
#include <ostream>
#include <string>
using namespace std;

//Milestone 1

struct Songs {
    string title;
    string artist;
    double hotness = 0.0;
    int orginalInd = 0;

};

inline void printSong(const Songs& song) {
    cout << song.title << "-" <<  song.artist
    << "(Hotness : " << song.hotness << endl;
}



#endif //SONGS_H
