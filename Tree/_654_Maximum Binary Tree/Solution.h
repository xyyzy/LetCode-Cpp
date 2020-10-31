//
// Created by Xulin on 2020/9/22.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class RandomizedCollection {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int lo, int hi) {
        if (lo>hi)
            return nullptr;

        //找到数组中最大值和对应索引
        int index=-1,maxval=INT_MIN;
        for (int i = lo; i <=hi ; ++i) {
            if (maxval<nums[i]) {
                index = i;
                maxval = nums[i];
            }
        }

        //用最大结点构造二叉树
        TreeNode* root =new TreeNode(maxval);
        root->left = build(nums,lo,index-1);
        root->right = build(nums,index+1,hi);
        return root;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
