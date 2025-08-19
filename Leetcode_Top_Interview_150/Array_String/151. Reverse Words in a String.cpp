#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        vector<string> words;

        string w;
        while(ss>>w) words.push_back(w);

        reverse(words.begin(), words.end());

        string answer = "";
        for(string w : words) {
            if(!answer.empty()) answer+=" ";
            answer+=w;
        }
        return answer;
    }
};