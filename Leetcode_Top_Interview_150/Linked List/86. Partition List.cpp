/*
    time: 25min 
    success: false  
    note: 마지막에 greaterPtr->next를 nullptr로 초기화해야 정상적인 결과값이 나옴. 사이클이 발생하는데 테스트환경에서는 사용이 끝나면
    메모리를 해제할 수 있음. -> use-after-free error 발생.
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* greater = new ListNode(0);
        ListNode* less = new ListNode(0);

        ListNode* greaterPtr = greater;
        ListNode* lessPtr = less;
        
        while(head!=nullptr) {
            cout<<"hell"<<endl;
            if(head->val < x) {
                lessPtr->next = head;
                lessPtr=lessPtr->next;
            }
            else {
                greaterPtr->next = head;
                greaterPtr=greaterPtr->next;
            }
            head=head->next;
        }
        
        greaterPtr->next = nullptr;
        lessPtr->next = greater->next;
        return less->next;
    }
};