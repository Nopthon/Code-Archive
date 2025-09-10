// For VSCode Coding
#include <bits/stdc++.h>
using namespace std;
//

/*
 * @lc app=leetcode.cn id=1733 lang=cpp
 *
 * [1733] 需要教语言的最少人数
 */

// @lc code=start
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // 核心：筛选出存在与朋友语言不通的人群，选择已学会人数最多的语言进行教学（贪心）
        // 首先 vector<vector<int>>& languages 的存储方式非常不容易筛选共同语言
        // 下面 lang 向量可以理解为邻接矩阵的存储形式
        int users = languages.size();
        vector<vector<int>> lang(users, vector<int>(n+1, 0));
        for(int i = 0; i < users; i++){
            for(int j = 0; j < languages[i].size(); j++){
                lang[i][languages[i][j]] = 1;
            }
        }
        // 现在定义：
        int barrier = 0;                    // 有多少人存在语言不通关系
        vector<int> lang_list(n+1,0);       // 记录所有“语言不通”的朋友对中第 i 个语言有多少人学过
        vector<int> vis(users,false);       // 避免重复记录某一个人
        // 筛选两个人是否语言不通
        for(int i = 0; i < friendships.size(); i++){
            bool check = false;
            for(int j = 0; j < languages[friendships[i][0]-1].size(); j++){
                if(lang[friendships[i][1]-1][languages[friendships[i][0]-1][j]] == 1){
                    check = true;
                    break;
                }
            }
            if(!check){
                int a = friendships[i][0]-1, b = friendships[i][1]-1;
                // 把 a 的数据加进 lang_list
                if(!vis[a]){
                    vis[a] = true;
                    barrier++;
                    for(int j = 0; j < languages[a].size(); j++){
                        lang_list[languages[a][j]] ++;
                    }
                }
                // b
                if(!vis[b]){
                    vis[b] = true;
                    barrier++;
                    for(int j = 0; j < languages[b].size(); j++){
                        lang_list[languages[b][j]] ++;
                    }
                }
            }
        }
        // 总人数 减去 最多人学习的语言的人数
        return barrier - *max_element(lang_list.begin(), lang_list.end());
    }
};
// @lc code=end
