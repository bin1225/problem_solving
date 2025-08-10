#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> count;
        for(int i=0; i<nums.size(); i++) {
            int cnt = ++count[nums[i]];
            if(cnt > nums.size()/2) {
                return nums[i];
            }
        }

        return 0;
    }
};