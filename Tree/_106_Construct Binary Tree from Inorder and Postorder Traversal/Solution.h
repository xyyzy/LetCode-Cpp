//
// Created by Xulin on 2020/9/22.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class RandomizedCollection {
    unordered_map<int, int> mp;
    int idx = 0, n;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &postorder, int postStart, int postEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;
        //找到根节点----postorder的尾结点
        int rootVal = postorder[postEnd];
        // 用rootVal去inorder中遍历找到相同值的下标
        int index = -1;
        for (int i = inStart; i <= inEnd; ++i) {
            if (rootVal == inorder[i]) {
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        int lefSize = index - inStart;//找出根节点左边结点的个数
        //左孩子
        root->left = build(postorder, postStart, postStart + lefSize-1 ,
                           inorder, inStart, index - 1);
        //右孩子
        root->right = build(postorder, postStart + lefSize, postEnd - 1,
                            inorder, index + 1, inEnd);
        return root;
    }


};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
