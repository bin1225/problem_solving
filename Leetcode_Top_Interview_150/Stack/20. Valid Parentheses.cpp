/*
    time: 10min 
    success: true 
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char,char> brackets = {{')','('}, {'}','{'},{']','['}};
        stack<char> stack;

        for(char c: s) {
            if(c=='('||c=='['||c=='{') stack.push(c);
            else {
                if(stack.empty() || stack.top() != brackets[c]) return false;
                else stack.pop();
            }
        }
        return stack.empty()? true:false;
    }
};