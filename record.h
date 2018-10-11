//
// Created by wojtek on 11.10.18.
//

#ifndef INVERTED_INDEX_CPP_RECORD_H
#define INVERTED_INDEX_CPP_RECORD_H

#include <fstream>



class record {
public:
    int id;
    float score;

    record(int id, float score);

    bool operator == (const record & r1){
        return r1.id == this->id;
    }

    bool operator >= (const record & r1){
        return r1.id <= this->id;
    }

    bool operator <= (const record & r1){
        return r1.id >= this->id;
    }

    bool operator > (const record & r1){
        return r1.id < this->id;
    }

    bool operator < (const record & r1){
        return r1.id > this->id;
    }
};


#endif //INVERTED_INDEX_CPP_RECORD_H
