/*
    time: 10min 
    success: true
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* now;
        now = head;
        unordered_map<ListNode*, bool> check;
        while(now->next !=NULL) {
            //cout<<now->val<<endl;
            if(check[now]) return true;
            check[now] = true;
            now = now->next;
        }
        return false;
    }
};