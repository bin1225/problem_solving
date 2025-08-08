#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
   
        int idx = 2;
        if(nums.size()<2) return nums.size();
        
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] != nums[idx-2]) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};