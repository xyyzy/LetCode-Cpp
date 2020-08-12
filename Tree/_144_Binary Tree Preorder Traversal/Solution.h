//
// Created by Xulin on 2020/8/12.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

/**
 * 先序遍历
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> list;
        TreeNode *curr = root;
        while (!stack.empty() || curr != NULL) {
            while (curr != NULL) {
                stack.push(curr);
            }
        }

    }
};


#endif //LETCODEC___SOLUTION_H
