//
// Created by Xulin on 2020/6/15.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

/*
 * 对称二叉树
 * */
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    bool isSymmetric(TreeNode *root) {
        return ismirror(root, root);
    }

    /*
     * 递归法
     * */
    bool ismirror(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (q->val == p->val)
            return ismirror(p->left, q->right) && ismirror(p->right, q->left);
        return false;
    }

    bool isSymmetric1(TreeNode *root) {
        queue<TreeNode *> queue;
        queue.push(root);
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* n1 = queue.front();
            queue.pop();
            TreeNode* n2 = queue.front();
            queue.pop();
            if (n1 == NULL && n2 == NULL) continue;
            if (n1 == NULL || n2 == NULL) return false;
            if (n1->val != n2->val) return false;
            queue.push(n1->left);
            queue.push(n2->right);
            queue.push(n1->right);
            queue.push(n2->left);
        }
        return true;
    }
};


#endif //LETCODEC___SOLUTION_H
