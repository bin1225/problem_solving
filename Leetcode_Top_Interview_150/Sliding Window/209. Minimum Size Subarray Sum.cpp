#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int i, j, sum;
        i = j = 0; sum = nums[i];
        while(j<nums.size()) {
            if(sum >= target) {
                min_len = min(min_len, j-i+1);
                sum-=nums[i]; i++;
            }
            else {
                j++;
                if(j<nums.size()) sum+=nums[j]; 
            }
        }
        if(min_len == INT_MAX) return 0;
        return min_len;
    }
};