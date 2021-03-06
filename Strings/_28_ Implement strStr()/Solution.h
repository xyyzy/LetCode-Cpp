//
// Created by Xulin on 2020/8/4.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <string>
#include <vector>

using namespace std;


class RandomizedCollection {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        //前处理needle和haystack从1开始
        vector<int> next(n);
        BuildNext(needle, next);
        int s, p;
        s = p = 0;
        while (s < n && p < m) {
            if (haystack[s] == needle[p]) {
                s++;
                p++;
            } else if (p > 0) p = next[p - 1] + 1;
            else s++;
        }
        return (p == m) ? (s - m) : -1;

    }

    void BuildNext(string pattern, vector<int> next) {
        int i, j;
        int m = pattern.length();
        next[0] = -1;
        for (j = 1; j < m; ++j) {
            i = next[j - 1];
            while ((i >= 0) && pattern[j] != pattern[i + 1]) {
                //回退
                i = next[i];
            }
            if (pattern[j] == pattern[i + 1]) {
                next[j] = i + 1;
            } else next[j] = -1;
        }
    }


};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
     