#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(int i=0; i<s.size(); i++) {
            if(isalnum(s[i])) ss+=tolower(s[i]);
        }

        int left = 0, right = ss.size()-1;
        while(left<right) {
            if(ss[left] != ss[right]) return false;
            left++; right--;
        }
        return true;
    }
};