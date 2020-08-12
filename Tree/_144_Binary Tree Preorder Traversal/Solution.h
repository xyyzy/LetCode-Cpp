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
        if (root== nullptr)
            return list;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* curr=stack.top();
            stack.pop();
            if  (curr != NULL) {
                list.push_back(curr->val);
            }
            if (curr->right!= nullptr)
                stack.push(curr->right);
            if (curr->left!= nullptr)
                stack.push(curr->left);
        }
        return list;
    }

    vector<int> preorderTraversal2(TreeNode *root){
        stack<TreeNode*> stack;
        vector<int> list;
        if (root== nullptr) {
            return list;
        }
        TreeNode *curr = root;
        while (!stack.empty()||curr!= nullptr){
            //找到最左边的节点
            while (curr!= nullptr){
                list.push_back(curr->val);
                stack.push(curr);
                curr=curr->left;
            }
            if (!stack.empty()){
                curr=stack.top();
                stack.pop();
                curr=curr->right;
            }
        }
        return list;
    }
};


#endif //LETCODEC___SOLUTION_H
