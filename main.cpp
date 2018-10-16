#include <iostream>
#include "MapUrlManager.h"
#include "MapRecordsManager.h"
#include "QueryBuilder.h"

int main() {
    auto *mapUrlManager = new MapUrlManager();

    auto *mapRecordsManager = new MapRecordsManager();

    //mapRecordsManager->printMap();

    mapRecordsManager->sortMapVectors();

    //mapRecordsManager->printRecords("reinforc");

    ///---Query 1---///

    auto *query1 = new QueryBuilder<int>(mapUrlManager);

    query1->startStoper();

    query1->mergeInnerJoin(mapRecordsManager->getRecordsIds("infantri"),mapRecordsManager->getRecordsIds("reinforc"));

    query1->mergeInnerJoin(mapRecordsManager->getRecordsIds("fire"),mapRecordsManager->getRecordsIds("brigad"));

    query1->mergeInnerJoin(0,1);

    query1->stopStoper();

    //query1->printUrls(2);

    std::cout<<"Rows: "<<query1->getLastQuerySize()<<std::endl;

    ///---Query 2---///

    auto *query2 = new QueryBuilder<int>(mapUrlManager);

    query2->startStoper();

    query2->mergeUnion(mapRecordsManager->getRecordsIds("infantri"),mapRecordsManager->getRecordsIds("reinforc"));

    query2->mergeUnion(mapRecordsManager->getRecordsIds("fire"),mapRecordsManager->getRecordsIds("brigad"));

    query2->mergeUnion(0,1);

    query2->stopStoper();

    //query2->printUrls(2);

    std::cout<<"Rows: "<<query2->getLastQuerySize()<<std::endl;

    ///---Query 3---///

    auto *query3 = new QueryBuilder<int>(mapUrlManager);

    query3->startStoper();

    query3->mergeUnion(mapRecordsManager->getRecordsIds("fire"),mapRecordsManager->getRecordsIds("brigad"));

    query3->mergeUnion(0,mapRecordsManager->getRecordsIds("infantri"));

    query3->mergeExcept(mapRecordsManager->getRecordsIds("reinforc"),1);

    query3->stopStoper();

    //query3->printUrls(2);

    std::cout<<"Rows: "<<query3->getLastQuerySize()<<std::endl;

    ///---Deleting---///

    delete mapUrlManager;

    delete mapRecordsManager;




    return 0;
}