//
// Created by Tatia on 10/27/2025.
//Edited by Deshna on 11/2/2025
//

#include <iostream>
#include <vector>
#include "../include//Songs.h"
#include "../include//io.h"
#include "../include//SortHeap.h"
using namespace std;

int main() {
    cout << "Loading songs is started" << endl;

    vector<Songs> songs = loadSongs("../../data/music.json");

    cout << "Total songs loaded is: " << songs.size() << endl;

    for (int i = 0; i < 5 && i < songs.size(); i++) {
        cout << i + 1 << ". "
            << songs[i].artist << " - "
            << songs[i].title
            << " Hotness: " << songs[i].hotness << endl;
    }

    return 0;
}