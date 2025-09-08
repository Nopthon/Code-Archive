// For VSCode Coding
#include <bits/stdc++.h>
struct ListNode { int val;ListNode *next;ListNode() : val(0), next(nullptr) {}ListNode(int x) : val(x), next(nullptr) {}ListNode(int x, ListNode *next) : val(x), next(next) {}
};using namespace std;
//

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* cur = head;
        while(cur->next != nullptr){
            if(cur->val != (cur->next)->val){
                cur = cur->next;
            }
            else {
                cur->next = cur->next->next; 
                // 考虑内存管理的话可以提前删除 cur->next
            }
        }
        return head;
    }
};
// @lc code=end

