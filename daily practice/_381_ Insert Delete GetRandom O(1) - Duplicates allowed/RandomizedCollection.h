//
// Created by Xulin on 2020/10/31.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___RANDOMIZEDCOLLECTION_H

/*
 * 设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

 *
 * */
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        //在idx末尾插入元素
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;


    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //不存在这个数
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = *(idx[val].begin());
        //返回末尾元素的引用
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
