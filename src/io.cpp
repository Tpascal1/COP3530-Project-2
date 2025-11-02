//
// Created by Tatiana on 10/27/2025.
//

#include "io.h"
<<<<<<< HEAD
#include "json.hpp"
#include "Songs.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

std:: vector<Songs> loadSongsStub() {
=======
#include <vector>
#include <string>
#include "Songs.h"
using namespace std;

std:: vector<Songs> loadSongs(const string& filename) {
>>>>>>> 88b68ad4da8bf6b3436464511d1fc670eb2e81ea
    return {
        {"Song A", "Artist 1", 0.90, 0}, {"Song B","Artist 2",0.90,1},
        {"Song C","Artist 3",0.50,2},
        {"Song D","Artist 4",0.90,3},
        {"Song E","Artist 5",0.10,4}
    };
};

<<<<<<< HEAD
static double readHotness(const json& item) {
    if ( item.contains("song") && item["song"].contains("hotness") ) {
        const auto & h = item["song"]["hotness"];
        if (h.is_number()) {
            return h.get<double>();
        }
        if (h.is_string()) {
            try {
                return std::stood(h.get<string>());

            }
            catch (...) {}
        }
    }
    return 0.0;
}

std::vector<Songs> loadSongs(const string& filename) {
    std::vector<Songs> song;

    std::ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return song;
    }

    json data;
    try {
        file >> data;
    }
    catch (const std::exception& e) {
        cerr << "Error: could not open file: " << filename << endl;
        return song;
    }

    int idx = 0;

    for (const auto& item : data) {
        if (!item.contains("song")) {
            continue;

        }

        const auto & s = item["song"];
        if (!s.contains("title") || !s.contains("artist")) {
            continue;
        }

        Songs song;
        try {
            song.title = s["title"].is_string() ? s["title"].get<string>() : "";
            song.artist = s["artist"].is_string() ? s["artist"].get<string>() : "";
        }
        catch (...) {
            continue;
        }


        song.hotness = readHotness(s);
        if (song.hotness == 0.0) {
            song.hotness = 0.0;
        }

        if (song.hotness > 1.0) {
            song.hotness = 1.0;
        }

        song.orginalInd = idx++;
        song.push_back(song);
    }
}
=======
>>>>>>> 88b68ad4da8bf6b3436464511d1fc670eb2e81ea

