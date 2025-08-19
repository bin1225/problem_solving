#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows <= 1) return s;

        vector<string> zig(numRows, "");
        
        int tmp = 0, dir = -1;

        for(int i=0; i<s.size(); i++) {
            if(tmp == numRows-1 || tmp == 0) dir*=-1;

            zig[tmp] += s[i];

            tmp+=dir;
        }

        string answer;
        for(string ss: zig) {
            answer+=ss;
        }
        return answer;
    }
};