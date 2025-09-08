// For VSCode Coding
#include <bits/stdc++.h>
struct ListNode { int val;ListNode *next;ListNode() : val(0), next(nullptr) {}ListNode(int x) : val(x), next(nullptr) {}ListNode(int x, ListNode *next) : val(x), next(next) {}
};using namespace std;
//

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode merged(1);
        ListNode *pivot = &merged;

        while (list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                pivot->next = list1;
                list1 = list1->next;
            }
            else{
                pivot->next = list2;
                list2 = list2->next;
            }
            pivot = pivot->next;
        }

        if(list1 != nullptr)
            pivot->next = list1;
        else pivot->next = list2;

        return merged.next;
    }
};
// @lc code=end

