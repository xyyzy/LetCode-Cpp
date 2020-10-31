//
// Created by Xulin on 2020/10/16.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


class RandomizedCollection {
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            A[i]=pow(A[i],2);
        }
        sort(A.begin(),A.end());
        return A;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
