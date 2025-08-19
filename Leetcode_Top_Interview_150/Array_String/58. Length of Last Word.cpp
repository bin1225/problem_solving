#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int idx = s.size()-1;
        while(idx>=0 && s[idx] == ' ') idx--;
        while(idx>=0 && s[idx] != ' ') {
            idx--; length++;
        }
        return length;
    }
};