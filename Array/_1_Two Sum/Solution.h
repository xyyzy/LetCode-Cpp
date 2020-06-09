//
// Created by Xulin on 2020/6/9.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    /*
     * 一遍哈希
     * */
    vector<int> twoSum1(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }

    /*
     * 两遍哈希
     * */
    vector<int> twoSum2(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (m.find(target - nums[j]) != m.end() &&m[target-nums[j]]!=j)//如果m中存在对应的键值，且不为i
                return {j,m[target-nums[j]]};
        }
        return {};
    }

};


#endif //LETCODEC___SOLUTION_H
