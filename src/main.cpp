//
// Created by Tatia on 10/27/2025.
//Edited by Deshna on 11/2/2025
//

#include <iostream>
#include <vector>
#include "Songs.h"
#include "io.h"
#include "SortHeap.h"
#include "UI.h"
#include <chrono>
#include "../include//SortHeap.h"
#include "../include//Songs.h"
#include "../include//io.h"
#include "../include//SortMerge.h"
using namespace std;
using namespace std::chrono; 

int main() {

    cout << "Loading songs is started" << endl;
    vector<Songs> songs = loadSongs("data/music.json");
    cout << "Total songs loaded is: " << songs.size() << endl;

    //checking if song list is empty
    if (songs.empty()) {
        cout << "No songs loaded" << endl;
        return 0;
    }

    ////Duplicating until we get to 100k songs
    size_t target = 100000;
    size_t ogsize = songs.size();
    while (songs.size() < target) {
        songs.push_back(songs[songs.size() % ogsize]);
    }
    cout << "The dataset is being expanded to " << songs.size() << endl;

    //Heap Sort Timing

    auto heapData = songs;
    auto mergeData = songs;


    cout << "\nSorting songs by hotness for Heap Sort:" << endl;
    auto startH = high_resolution_clock::now();
    heapSort(heapData);
    auto endH = high_resolution_clock::now();
    auto durationH = duration_cast<milliseconds>(endH - startH);
    cout << "Heap Sort completed in" << durationH.count() << "ms" << endl;

    //Merge Sort Timing
    cout << "\nSorting songs by hotness for Merge Sort:" << endl;
    auto start = high_resolution_clock::now();
    mergeSort(mergeData);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Merge Sorge completed in" << duration.count() << "ms" << endl;

    cout << "\nTop 5 songs after sorting by descending order:\n";
    for (int i = 0; i < songs.size(); i++) {
        cout << i + 1 << ". " << songs[i].artist
            << " - " << songs[i].title
            << " | Hotness: " << songs[i].hotness << endl;
    }


    launchUI();

    return 0;
}