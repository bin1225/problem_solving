#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        for(int i=0; i<strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i] != c) {
                    return answer;
                }
            }
            answer+=c;
        }
        return answer;
    }
};