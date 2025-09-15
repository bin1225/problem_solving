/*
    time: 15min 
    success: false
    note: 포인터 다루는데 적응을 제대로 못한듯, 
*/

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
#include<bits/stdc++.h>
using namespace std;

 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode dummy(0);
        ListNode *node = &dummy;
        while(l1 != NULL || l2 !=NULL || carry !=false) {
            int a = l1 != NULL ? l1->val : 0;
            int b = l2 != NULL ? l2->val : 0;

            int num = a + b + carry;
            carry = false;
            if(num >= 10) {
                num%=10; carry = true;
            }

            node->next = new ListNode(num);
            node = node->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return dummy.next;
    }
};