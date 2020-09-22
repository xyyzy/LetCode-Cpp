//
// Created by Xulin on 2020/9/22.
//

#ifndef LETCODEC___SOLUTION_H
#define LETCODEC___SOLUTION_H

/*
 * 105. 从前序与中序遍历序列构造二叉树*/

#include <cstdio>
#include <vector>
#include <stack>
#include <climits>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> mp;
    int idx = 0, n;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        //找到根节点----preorder的头结点
        int rootVal = preorder[preStart];
        // 用rootVal去inorder中遍历找到相同值的下标
        int index = -1;
        for (int i = 0; i <= inEnd; ++i) {
            if (rootVal == inorder[i]) {
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        int lefSize = index - inStart;//找出根节点左边结点的个数
        //左孩子
        root->left = build(preorder, preStart + 1, preStart + lefSize,
                           inorder, inStart, index - 1);
        //右孩子
        root->right = build(preorder, preStart + lefSize + 1, preEnd,
                            inorder, index + 1, inEnd);
        return root;
    }


    /**
     *
     * 更快解法 其实也类似
     * */
    TreeNode* buildTree2(vector<int>& pre, vector<int>& in) {
        n = in.size();
        //哈希定位,将中序遍历每个元素定位
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return bt(pre, 0, n - 1);
    }

    TreeNode* bt(vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;
        int i = mp[pre[idx]];

        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = bt(pre, l, i - 1);
        root->right = bt(pre, i + 1, r);
        return root;
    }

};


#endif //LETCODEC___SOLUTION_H
