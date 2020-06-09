//
// Created by Xulin on 2020/6/9.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while (i < j) {
            //计算面积
            int temp = (j - i) * min(height[j], height[i]);
            res = max(res, temp);
            if (height[i]<height[j])
                i++;
            else
                j--;
        }
        return res;

    }
};


#endif //LETCODEC___SOLUTION_H
