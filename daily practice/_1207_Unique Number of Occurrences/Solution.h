//
// Created by Xulin on 2020/10/28.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
    //哈希表
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> occur;
        for (const auto &x:arr) {
            occur[x]++;
        }
        unordered_set<int> time;
        /*for (const auto &x:occur) {
            time.insert(x.second);
        }*/
        //也可
        for(pair<int,int> i :occur){
            time.insert(i.second);
        }
        return time.size() == occur.size();
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
