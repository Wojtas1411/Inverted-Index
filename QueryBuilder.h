//
// Created by wojtek on 11.10.18.
//

#ifndef INVERTED_INDEX_CPP_QUERYBUILDER_H
#define INVERTED_INDEX_CPP_QUERYBUILDER_H

#include <vector>
#include "record.h"
#include "MapUrlManager.h"

template <class T>
class QueryBuilder {
private:
    std::vector<std::vector<T>> container;
    MapUrlManager *myMap = nullptr;
    clock_t start = 0;
    clock_t stop = 0;


public:
    QueryBuilder() = default;

    explicit QueryBuilder(MapUrlManager *a){
        this->myMap = a;
    }

    void mergeInnerJoin(std::vector<T> v1, std::vector<T> v2){
        int i = 0, j = 0;
        //std::cout<<v1.size()<<" "<<v2.size()<<std::endl;
        std::vector<T> output;
        while(i < v1.size() and j < v2.size()){
            if(v1[i] == v2[j]){
                output.push_back(v1[i]);
                i++;
                j++;
            } else if(v1[i] < v2[j]){
                i++;
            } else {
                j++;
            }
        }

        container.push_back(output);
    }

    void mergeInnerJoin(std::vector<T> v1, int n){
        mergeInnerJoin(v1, container[n]);
    }

    void mergeInnerJoin(int n, std::vector<T> v2){
        mergeInnerJoin(container[n], v2);
    }

    void mergeInnerJoin(int n1, int n2){
        mergeInnerJoin(container[n1], container[n2]);
    }

    void mergeUnion(std::vector<T> v1, std::vector<T> v2){
        int i=0, j=0;
        //std::cout<<v1.size()<<" "<<v2.size()<<std::endl;
        std::vector<T> output;
        while(i < v1.size() or j < v2.size()){
            if(v1[i]==v2[j]){
                output.push_back(v1[i]);
                i++;
                j++;
            } else if(v1[i] < v2[j] and i < v1.size()) {
                output.push_back(v1[i]);
                i++;
            } else if(j < v2.size()) {
                output.push_back(v2[j]);
                j++;
            } else if(i < v1.size()) {
                output.push_back(v1[i]);
                i++;
            }

        }

        container.push_back(output);
    }

    void mergeUnion(std::vector<T> v1, int n){
        mergeUnion(v1, container[n]);
    }

    void mergeUnion(int n, std::vector<T> v2){
        mergeUnion(container[n],v2);
    }

    void mergeUnion(int n1, int n2){
        mergeUnion(container[n1],container[n2]);
    }

    void mergeExcept(std::vector<T> v1, std::vector<T> v2){
        int i = 0, j = 0;
        //std::cout<<v1.size()<<" "<<v2.size()<<std::endl;
        std::vector<T> output;
        while(i < v1.size() or j < v2.size()){
            if(v1[i] == v2[j]){
                i++;
                j++;
            } else if(v1[i] < v2[j] and i < v1.size()) {
                output.push_back(v1[i]);
                i++;
            } else if(j < v2.size()){
                j++;
            } else if(i < v1.size()){
                output.push_back(v1[i]);
                i++;
            }
        }

        container.push_back(output);
    }

    void mergeExcept(std::vector<T> v1, int n){
        mergeExcept(v1, container[n]);
    }

    void mergeExcept(int n, std::vector<T> v2){
        mergeExcept(container[n], v2);
    }

    void mergeExcept(int n1, int n2){
        mergeExcept(container[n1],container[n2]);
    }

    void printUrls(int i){
        for(auto it : container[i]){
            std::cout<<myMap->getURL(it)<<"\n";
        }
    }

    int getLastQueryIndex(){
        return (int)container.size()-1;
    }

    int getLastQuerySize(){
        return (int)container[this->getLastQueryIndex()].size();
    }

    void startStoper(){
        start = clock();
    }

    void stopStoper(){
        stop = clock();
        std::cout<<"Query time: "<<(double)(stop-start)/CLOCKS_PER_SEC<<" s"<<std::endl;
    }
};


#endif //INVERTED_INDEX_CPP_QUERYBUILDER_H
