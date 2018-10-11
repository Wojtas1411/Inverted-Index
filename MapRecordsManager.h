//
// Created by wojtek on 11.10.18.
//

#ifndef INVERTED_INDEX_CPP_MAPRECORDSMANAGER_H
#define INVERTED_INDEX_CPP_MAPRECORDSMANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include "record.h"

class MapRecordsManager {
private:
    std::unordered_map<std::string, std::vector<record>> MapRecords;
public:
    MapRecordsManager();
    ~MapRecordsManager() = default;

    void printMap();

    void printRecords(std::string term);

    void sortMapVectors();

};


#endif //INVERTED_INDEX_CPP_MAPRECORDSMANAGER_H
