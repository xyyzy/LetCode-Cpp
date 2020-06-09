//
// Created by Xulin on 2020/6/9.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i <nums.size(); ++i) {
            for (int j = i+1; j <nums.size() ; ++j) {
                if (nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        for (int i = 0; i <nums.size(); ++i) {
            for (int j = i+1; j <nums.size() ; ++j) {
                if (nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }

};


#endif //LETCODEC___SOLUTION_H
