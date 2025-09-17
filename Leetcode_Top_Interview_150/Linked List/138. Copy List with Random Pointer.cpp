/*
    time: 20min 
    success: true 
    note: 
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> hash;
        Node dummy(0);
        Node * node = &dummy;

        while(head) {
            node->next = new Node(head->val);   
            node->next->random = head->random;
            hash[head] = node->next;
            node = node->next;
            head = head->next;
        }

        node = dummy.next;
        while(node) {
            node->random = hash[node->random];
            node=node->next;
        }

        return dummy.next;
    }
};