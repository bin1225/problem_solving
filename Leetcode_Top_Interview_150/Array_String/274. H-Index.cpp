#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        for(int i=1; i<=1000; i++) {
            int count = 0;
            for(int j=0; j<citations.size(); j++) {
                if(i<=citations[j]) count++;
            }
            if(count<i) {
                return i-1;
            } 
        }
        return 0;
    }
};