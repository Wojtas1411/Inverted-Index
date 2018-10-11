//
// Created by wojtek on 11.10.18.
//

#include "MapUrlManager.h"

MapUrlManager::MapUrlManager() {
    std::ifstream in;
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in.open("Wikipedia-EN-20120601_REVISION_URIS.TSV");

    clock_t start = clock();

    while (!in.eof()){
        int temp_id;
        std::string temp_url;

        in>>temp_id;
        in>>temp_url;

        MapURLS[temp_id] = temp_url;

    }

    clock_t end = clock();

    std::cout<<"URLS: Bulkloading time:\t"<<((double)(end-start))/CLOCKS_PER_SEC<<" s"<<std::endl;

    in.close();
}


std::string MapUrlManager::getURL(int id) {
    return MapURLS[id];
}
