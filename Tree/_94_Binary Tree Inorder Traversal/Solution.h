//
// Created by Xulin on 2020/8/12.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

/**
 * 中序遍历
 *
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class RandomizedCollection {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack;
        vector<int> list;
        TreeNode *cur = root;
        while (!stack.empty() || cur != NULL) {
            while (cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }
            //获取栈顶元素并删除
            cur = stack.top();
            stack.pop();
            //将值压住list中
            list.push_back(cur->val);
            cur = cur->right;
        }
        return list;
    }

};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
