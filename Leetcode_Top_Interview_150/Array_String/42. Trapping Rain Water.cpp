#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int answer, left_max, right_max, left, right;
        answer = 0;
        right = height.size()-1; right_max = height[right];
        left = 0; left_max = height[left];
    
        while(left < right) {
            if(left_max < right_max) {
                answer += left_max - height[left];
                left++;
                left_max = max(left_max, height[left]);    
            }
            else {
                answer += right_max - height[right];
                right--;
                right_max = max(right_max, height[right]);
            }
        }
        return answer;
    }
};