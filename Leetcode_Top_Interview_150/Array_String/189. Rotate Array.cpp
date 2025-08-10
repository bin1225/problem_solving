#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            int idx = (i+k) % nums.size();
            ans[idx] = nums[i];
        }
        nums = ans;
    }
};