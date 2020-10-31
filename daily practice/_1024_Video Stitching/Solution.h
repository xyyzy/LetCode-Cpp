//
// Created by Xulin on 2020/10/24.
//

#ifndef LETCODEC___RANDOMIZEDCOLLECTION_H
#define LETCODEC___SOLUTION_H

#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/*
 * 你将会获得一系列视频片段，这些片段来自于一项持续时长为 T 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。

视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1] 结束。
 我们甚至可以对这些片段自由地再剪辑，例如片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。

我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, T]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。

 * */
class RandomizedCollection {
public:
    //动态规划
    int videoStitching(vector<vector<int>> &clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; ++i) {
            for (auto &it:clips) {
                if (it[0] < i && i <= it[1]) {
                    dp[i] = min(dp[i], dp[it[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }

    //贪心
    static bool cpm(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }

    int videoStitching1(vector<vector<int>> &clips, int T) {
        int t = 0;
        sort(clips.begin(), clips.end(), cpm);
        int i = 0, ans = 0, last_t;
        while (i < clips.size() && t < T) {
            if (clips[i][0] <= t) {
                last_t = t;
                while (i < clips.size() && clips[i][0] <= last_t) {
                    t = max(t, clips[i][1]);
                    i++;
                }
                ans++;
            } else {
                break;
            }
        }
        return t >= T ? ans : -1;
    }
};


#endif //LETCODEC___RANDOMIZEDCOLLECTION_H
