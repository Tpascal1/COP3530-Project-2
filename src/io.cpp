//
// Created by Tatiana on 10/27/2025.
//Edited by Deshna N on 11/1/2025
//

#include "io.h"
#include <vector>
#include <string>
#include "Songs.h"
#include "../include/json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;


vector<Songs> loadSongs(const string& filename) {
    vector<Songs> songs; 
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error in reading file, could not open" << filename << endl;
        return songs; 
    }

    //https://stackoverflow.com/questions/32205981/reading-json-files-in-c
    json data;
    file >> data;

    cout << "File opened with success" << endl; 

    file.close();

    int index = 0;

    for (int i = 0; i < data.size(); i++) {
        Songs s;

        //Checking artist name
        if (data[i]["artist"]["name"].is_string()) {
            s.artist = data[i]["artist"]["name"];
        }
        else {
            s.artist = "Not known";
        }
        //Checking song id
        if (data[i]["song"]["id"].is_string()) {
            s.title = data[i]["song"]["id"];
        }
        else {
            s.title = "No ID";
        }
        //Checking song hotness
        if (data[i]["song"]["hotttnesss"].is_number()) {
            s.hotness = data[i]["song"]["hotttnesss"];
        }
        else {
            s.hotness = -1.0;  //return -1 for hotness if not found
        }

        s.orginalInd = index;

        if (s.hotness >= 0.0) {
            songs.push_back(s);
            index++;
        }
    }

    cout << "Songs with valid name id and hotness: " << songs.size() << endl;
    return songs;
}

std:: vector<Songs> loadSongsStub() {
    return {
        {"Song A", "Artist 1", 0.90, 0}, {"Song B","Artist 2",0.90,1},
        {"Song C","Artist 3",0.50,2},
        {"Song D","Artist 4",0.90,3},
        {"Song E","Artist 5",0.10,4}
    };
};
