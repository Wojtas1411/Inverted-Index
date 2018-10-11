//
// Created by wojtek on 11.10.18.
//

#ifndef INVERTED_INDEX_CPP_MAPURLMANAGER_H
#define INVERTED_INDEX_CPP_MAPURLMANAGER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

class MapUrlManager {
private:
    std::unordered_map<int, std::string> MapURLS;

public:
    MapUrlManager();

    ~MapUrlManager() = default;

    std::string getURL(int id);

};


#endif //INVERTED_INDEX_CPP_MAPURLMANAGER_H
