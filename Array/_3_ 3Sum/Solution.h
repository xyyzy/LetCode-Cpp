//
// Created by Xulin on 2020/6/9.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 双指针
     * */
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) return res;
        int l, r;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;//因为最小值已经大于0所以三数之和一定大于0
            if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
            l = i + 1;
            r = nums.size() - 1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while (l<r && nums[l] == nums[l+1]) l++; // 去重
                    while (l<r && nums[r] == nums[r-1]) r--; // 去重
                    l++;
                    r--;
                }
                else if(sum>0)r-=1;
                else l+=1;
            }
        }
        return res;
    }


};


#endif //LETCODEC___SOLUTION_H
