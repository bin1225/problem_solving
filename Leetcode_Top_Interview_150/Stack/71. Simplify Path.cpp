/*
    time: 11min
    success: true
    note: 특정 기호로 pasing -> getline(input, token, '기호');
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string answer, token;
        stringstream ss(path);
        while (getline(ss, token, '/')) { // '/' 기준으로 split
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }
        for(string s: st) {
            answer+="/"+s;
        }
        return answer.empty() ? "/":answer;
    }
};