//
// Created by Tatia on 10/27/2025.
//Edited by Deshna on 11/2/2025
//

#include <iostream>
#include <vector>
#include <chrono>
#include "../include//Songs.h"
#include "../include//io.h"
#include "../include//SortMerge.h"
using namespace std;
using namespace std::chrono; 

int main() {

    cout << "Loading songs is started" << endl;
    vector<Songs> songs = loadSongs("../../data/music.json");
    cout << "Total songs loaded is: " << songs.size() << endl;

    ////duplicating until we get to 100k songs
    int target = 100000;
    int ogsize = songs.size();
    while (songs.size() < target) {
        songs.push_back(songs[songs.size() % ogsize]);
    }
    cout << "The dataset is being expanded to " << songs.size();



    cout << "\nSorting songs by hotness for Merge Sort:" << endl;
    auto start = high_resolution_clock::now();
    mergeSort(songs);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Merge Sorge completed in" << duration.count() << "ms" << endl;
    
    cout << "\nTop 5 songs after sorting by descending order:\n";
    for (int i = 0; i < songs.size(); i++) {
        cout << i + 1 << ". " << songs[i].artist
            << " - " << songs[i].title
            << " | Hotness: " << songs[i].hotness << endl;
    }
    // cout << "Loading songs is started" << endl;

    // vector<Songs> songs = loadSongs("../../data/music.json");

    // cout << "Total songs loaded is: " << songs.size() << endl;

    // for (int i = 0; i < 5 && i < songs.size(); i++) {
    //     cout << i + 1 << ". "
    //         << songs[i].artist << " - "
    //         << songs[i].title
    //         << " Hotness: " << songs[i].hotness << endl;
    // }

    return 0;
}