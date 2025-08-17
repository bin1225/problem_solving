#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;

        int num = 0;
        for(int i=0; i<s.size()-1; i++) {
            if(hash[s[i]] < hash[s[i+1]]) num -=hash[s[i]];
            else num+=hash[s[i]];
        }
        num += hash[s.back()];
        return num;
    }
};