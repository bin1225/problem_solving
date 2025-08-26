#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> answer;

        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(binary_search(nums.begin()+j+1, nums.end(), -(nums[i]+nums[j]))){
                    s.insert({nums[i], nums[j], -(nums[i]+nums[j])});
                }
            }
        }
        for(auto a: s) answer.push_back(a);
        return answer;
    }
};