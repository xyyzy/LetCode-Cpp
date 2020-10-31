//
// Created by Xulin on 2020/8/4.
//

//#include "RandomizedCollection.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int findsearch(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();
    //前处理needle和haystack从1开始
    vector<int> next(n);
    BuildNext(needle, next);
    int s, p;
    s = p = 0;
    while (s < m&& p < m) {
        if (haystack[s] == needle[p]) {
            s++;
            p++;
        } else if (p > 0) p = next[p - 1] + 1;
        else s++;
    }
    return (p == m) ? (s - m) : -1;

}


int main() {
    std::string s = "hello";
    std::string n = "ll";
    int i = findsearch(s, n);
    cout<<i;
    return 0;
}