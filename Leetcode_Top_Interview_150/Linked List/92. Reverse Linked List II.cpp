/*
    time: 15min 
    success: 
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        ListNode *curr = head;
        stack<int> st;
        while(curr) {
            if(idx>=left && idx<=right) {
                st.push(curr->val);
            }
           curr = curr->next; idx++;
        }
        curr = head;
        idx = 1;
        while(curr) {
            if(idx>=left && idx<=right) {
                curr->val = st.top();
                st.pop();
            }
           curr = curr->next; idx++;
        }
        return head;
    }
};