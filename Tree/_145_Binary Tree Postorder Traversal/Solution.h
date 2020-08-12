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
 * 后序遍历
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    利用前序遍历 根-左-右  后序遍历 左-右-根
    所以先变成 根-右-左
    先按前序遍历的规则 然后reverse
 *
 * */
class Solution {
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> list;
        stack.push(root);
        if (root==NULL)
            return list;
        while (!stack.empty()) {
            TreeNode *curr = stack.top();
            stack.pop();
            list.push_back(curr->val);
            //先入后出所以
            if (curr->left != NULL) {
                stack.push(curr->left);
            }
            if (curr->right != NULL) {
                stack.push(curr->right);
            }
        }
        reverse(list.begin(),list.end());
        return list;
    }
};


#endif //LETCODEC___SOLUTION_H
