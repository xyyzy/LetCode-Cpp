//
// Created by Xulin on 2020/10/14.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

/*
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
 * 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 你可以按任意顺序返回答案。
 * */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class RandomizedCollection {
public://计数法
    vector<string> commonChars(vector<string> &A) {
        vector<string> ans;
        int count[26];
        for (int i = 0; i < 26; ++i) {
            count[i] = 101;
        }
        for (int i = 0; i < A.size(); ++i) {
            //记录每个字符串中 每个字符出现的次数
            int word[26] = {0};
            for (int j = 0; j < A[i].size(); ++j) {
                word[A[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; ++k) {
                count[k] = min(count[k], word[k]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                for (int j = 0; j < count[i]; ++j) {
                    string str;
                    str.push_back('a' + i);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
