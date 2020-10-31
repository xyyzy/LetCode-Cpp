//
// Created by Xulin on 2020/10/15.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <cstddef>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class RandomizedCollection {
    Node *connect1(Node *root) {
        if (root == nullptr)
            return nullptr;
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node *temp = nullptr;
            int size = queue.size(); //当前层有多少个结点
            for (int i = 0; i < size; ++i) {//依次取出当前层结点
                Node *cur = queue.front();
                queue.pop();
                if (i > 0) {
                    temp->next = cur;//添加链接
                }
                temp = cur;//更新节点
                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);

            }
        }
        return root;
    }
    Node *connect2(Node *root){
        if (root== nullptr)
            return nullptr;
        Node * leftmost = root;
        //因为是完美二叉树，只需判断左节点是否存在
        while (leftmost->left!= nullptr){
            Node* temp = leftmost;
            while (temp!= nullptr){
                //第一种情况 同一父节点下
                temp->left->next = temp->right;
                //第二种情况 在不同父节点下
                if (temp->next!= nullptr){
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            //始终指向最左端
            leftmost = leftmost->left;
        }
        return root;
    }

};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
