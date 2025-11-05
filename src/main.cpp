#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include "Songs.h"
#include "io.h"
#include "SortHeap.h"
#include "SortMerge.h"
using namespace std;
using namespace std::chrono;

void waitForUser(const std::string& message = "Press Enter to continue...") {
    std::cout << "\n" << message;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {


    cout << "Loading songs is started" << endl;
    vector<Songs> songs = loadSongs("data/music.json");
    cout << "Total songs loaded is: " << songs.size() << endl;

    // Check if song list is empty
    if (songs.empty()) {
        cout << "No songs loaded" << endl;
        return 0;
    }

    // Duplicate until 100k for timing
    const size_t target = 100000;
    const size_t ogsize = songs.size();
    while (songs.size() < target) {
        songs.push_back(songs[songs.size() % ogsize]);
    }
    cout << "The dataset is being expanded to " << songs.size() << endl;

    // Separate copies for each sort
    auto heapData  = songs;
    auto mergeData = songs;

    // ---- Heap Sort Timing ----
    cout << "\nSorting songs by hotness for Heap Sort:" << endl;
    auto startH = high_resolution_clock::now();
    heapSort(heapData); // sorts in place
    auto endH = high_resolution_clock::now();
    auto durationH = duration_cast<milliseconds>(endH - startH);
    cout << "Heap Sort completed in " << durationH.count() << " ms" << endl;

    // ---- Merge Sort Timing ----
    cout << "\nSorting songs by hotness for Merge Sort:" << endl;
    auto startM = high_resolution_clock::now();
    mergeSort(mergeData); // sorts in place
    auto endM = high_resolution_clock::now();
    auto durationM = duration_cast<milliseconds>(endM - startM);
    cout << "Merge Sort completed in " << durationM.count() << " ms" << endl;

    waitForUser("Press Enter to continue...");
    printSongs(heapData, "Heap Sort Results (descending hotness):");

    waitForUser("Press Enter to continue...");
    printSongs(mergeData, "Merge Sort Results (descending hotness):");

    waitForUser("Press to Exit...");
}