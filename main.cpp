#include <iostream>
#include "MapUrlManager.h"
#include "MapRecordsManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto *mapUrlManager = new MapUrlManager();

    auto *mapRecordsManager = new MapRecordsManager();

    //mapRecordsManager->printMap();

    mapRecordsManager->sortMapVectors();

    mapRecordsManager->printRecords("reinforc");



    delete mapUrlManager;

    delete mapRecordsManager;




    return 0;
}