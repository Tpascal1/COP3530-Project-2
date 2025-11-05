//
// Created by Tatiana on 10/23/2025.
//

#ifndef SONGS_H
#define SONGS_H


#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

//Milestone 1

struct Songs {
    string title;
    string artist;
    double hotness = 0.0;
    int orginalInd = 0;

};

inline void printSongs(const std::vector<Songs>& data,
                       const std::string& label = "",
                       size_t limit = 0) {
    using namespace std;
    if (!label.empty()) cout << "\n" << label << "\n";

    size_t count = (limit == 0 || limit > data.size()) ? data.size() : limit;
    for (size_t i = 0; i < count; ++i) {
        cout << i + 1 << ". " << data[i].artist
             << " - " << data[i].title
             << " | Hotness: " << data[i].hotness << "\n";
    }
}



#endif //SONGS_H
