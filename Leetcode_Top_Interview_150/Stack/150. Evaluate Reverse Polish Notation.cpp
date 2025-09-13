/*
    time: 8min 
    success: true
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for(int i=0; i<tokens.size(); i++) {
            if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")) {
                nums.push_back(stoi(tokens[i]));
            }
            else {
                int b = nums.back(); nums.pop_back();
                int a = nums.back(); nums.pop_back();
                
                if(tokens[i] == "/") nums.push_back(a/b);
                if(tokens[i] == "+") nums.push_back(a+b);
                if(tokens[i] == "-") nums.push_back(a-b);
                if(tokens[i] == "*") nums.push_back(a*b);
            }
        }

        return nums.back();
    }
};