/*
    time: 20min 
    success: fasle 
    note: idea는 맞았는데, pointer가 null이 되는 지점을 정확히 처리하지 못했음. k%=size 후 k==0인 경우는 그냥 배열을 return
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        ListNode* last = head;
        int size = 1;        
        while(last->next) {
            last = last->next;
            size++;
        }

        k%=size;
        if(k==0) return head;
        
        ListNode* start;
        ListNode* curr = head;
        for(int i=0; i<size - k - 1; i++) {
            curr = curr->next;
        }
        start = curr->next;
        curr->next = NULL;
        last->next = head;
        return start;
    }
};