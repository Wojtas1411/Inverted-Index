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

    friend std::ostream& operator<<(std::ostream& os, const record & obj) {
        // write obj to stream
        os<<"(id: "<<obj.id<<" score: "<<obj.score<<")";
        return os;
    }
};


#endif //INVERTED_INDEX_CPP_RECORD_H
