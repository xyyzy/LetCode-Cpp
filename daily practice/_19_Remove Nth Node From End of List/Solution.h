//
// Created by Xulin on 2020/10/18.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H
using namespace std;

#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RandomizedCollection {
public:
    /*
     * 两个结点保持n的距离 当前个结点到达边界的时候后一个结点就是要删除的结点。
     * */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *temp = new ListNode(0);
        if (!head) return nullptr;
        head->next = temp;
        //前
        ListNode *fast = temp;
        //后
        ListNode *slow = temp;
        while (n > 0) {
            fast = fast->next;
            n--;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *res = temp->next;
        delete temp;
        return res;
    }

    /*
     * 栈遍历
     * */
    ListNode *removeNthFromEnd2(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        stack < ListNode * > stk;
        ListNode *cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode *prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
