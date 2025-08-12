#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;

        vector<int> forward;
        vector<int> backward;
        int forward_mul = 1;
        int backward_mul = 1;
        for(int i=0; i<nums.size(); i++) {
            forward_mul *= nums[i];
            backward_mul *= nums[nums.size()-1-i];
            forward.push_back(forward_mul);
            backward.push_back(backward_mul);
        }
        reverse(backward.begin(), backward.end());

        answer.push_back(backward[1]);
        for(int i=1; i<nums.size()-1; i++) {
            answer.push_back(forward[i-1] * backward[i+1]);
        }
        answer.push_back(forward[nums.size()-2]);
        return answer;
    }
};