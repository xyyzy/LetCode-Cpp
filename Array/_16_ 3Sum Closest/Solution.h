//
// Created by Xulin on 2020/6/10.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class RandomizedCollection {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int l, r;
        for (int i = 0; i < nums.size(); ++i) {
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                }
                if (sum - target > 0) r--;
                if (sum - target < 0) l++;
                if (sum==target)
                    return ans;
            }
        }
        return ans;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
