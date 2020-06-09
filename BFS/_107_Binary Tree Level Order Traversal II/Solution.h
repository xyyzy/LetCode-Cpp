//
// Created by Xulin on 2020/6/8.
//

#ifndef TEST_SOLUTION_H
#define TEST_SOLUTION_H


#include <cstddef>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        //保存节点用于遍历
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            //保存每一层遍历结果
            vector<int> curlevel;
            int size = queue.size();
            for(int i=0;i<size;i++){
                TreeNode* cur  = queue.front();
                queue.pop();
                curlevel.push_back(cur->val);
                if (cur->left!=NULL)
                    queue.push(cur->left);
                if(cur->right!=NULL)
                    queue.push(cur->right);
            }
            result.insert(result.begin(),curlevel);

        }
        return result;
    }

};


#endif //TEST_SOLUTION_H
