//
// Created by Tatiana on 10/23/2025.
//

#ifndef SONGS_H
#define SONGS_H


#include <iostream>
#include <ostream>
#include <string>
using namespace std;


struct Songs {
    string Title;
    string Artist;
    double Hotness = 0.0;
    int OrginalInd = 0;

};

inline void printSong(const Songs& song) {
    cout << song.Title << "-" <<  song.Artist
    << "(Hotness : " << song.Hotness << endl;
}



#endif //SONGS_H
