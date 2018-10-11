//
// Created by wojtek on 11.10.18.
//

#include "MapRecordsManager.h"


MapRecordsManager::MapRecordsManager() {
    char buf[16184];
    std::ifstream in;
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in.rdbuf()->pubsetbuf(buf, 16184);

    in.open("Wikipedia-EN-20120601_KEYWORDS.TSV");

    clock_t start = clock();

    while (!in.eof()){
        int temp_id;
        float temp_score;
        std::string temp_term;

        in>>temp_id;
        in>>temp_term;
        in>>temp_score;

        record temp_record = record(temp_id,temp_score);

        MapRecords[temp_term].push_back(temp_record);

    }

    clock_t end = clock();

    std::cout<<"KEYWORDS: Bulkloading time:\t"<<((double)(end-start))/CLOCKS_PER_SEC<<" s"<<std::endl;

    in.close();

    in.close();
}

void MapRecordsManager::printMap() {
    for(auto it = MapRecords.begin(); it!= MapRecords.end(); it++){
        std::cout<<it->first<<":\t";
        for(auto j : MapRecords[it->first]){
            std::cout<<"("<<j.id<<", "<<j.score<<")";
        }
        std::cout<<std::endl;
    }
}

void MapRecordsManager::printRecords(std::string term) {
    std::cout<<term<<":\t";
    for(auto i :MapRecords[term]){
        std::cout<<"("<<i.id<<", "<<i.score<<")";
    }
    std::cout<<std::endl;
}

void MapRecordsManager::sortMapVectors() {

    clock_t start = clock();

    for(auto it = MapRecords.begin(); it != MapRecords.end(); it++){
        sort(MapRecords[it->first].begin(), MapRecords[it->first].end());
    }

    clock_t end = clock();

    std::cout<<"KEYWORDS: Sorting time:\t"<<((double)(end-start))/CLOCKS_PER_SEC<<" s"<<std::endl;

}

std::vector<int> MapRecordsManager::getRecordsIds(std::string term) {
    std::vector<int> output;
     for(auto i : MapRecords[term]){
         output.push_back(i.id);
     }
    return output;
}

std::vector<record> MapRecordsManager::getRecords(std::string term) {
    return MapRecords[term];
}
