//
// Created by Tatiana on 10/27/2025.
//

#include "io.h"
#include <vector>
#include <string>
#include "Songs.h"
using namespace std;

std:: vector<Songs> loadSongs(const string& filename) {
    return {
        {"Song A", "Artist 1", 0.90, 0}, {"Song B","Artist 2",0.90,1},
        {"Song C","Artist 3",0.50,2},
        {"Song D","Artist 4",0.90,3},
        {"Song E","Artist 5",0.10,4}
    };
};


