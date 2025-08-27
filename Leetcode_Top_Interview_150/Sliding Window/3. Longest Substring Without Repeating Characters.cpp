#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> exist;
        int left = 0, right = 0;
        int answer = 0;
        while(right < s.size()) {
            if(exist[s[right]]) {
                while(exist[s[right]]) {
                    exist[s[left]] = false;
                    left++; 
                }
            }
            answer = max(answer, right-left+1);
            exist[s[right]] = true;
            right++;
        }

        return answer;
    }
};