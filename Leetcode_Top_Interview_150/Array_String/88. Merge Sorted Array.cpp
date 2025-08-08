#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int idx1, idx2;
        idx1=idx2=0;
        while(idx1<m && idx2<n) {
            if(nums1[idx1] < nums2[idx2]) {
                ans.push_back(nums1[idx1++]);
            }
            else {
                ans.push_back(nums2[idx2++]);
            }
        }

        for(;idx1<m;idx1++) ans.push_back(nums1[idx1]);
        for(;idx2<n;idx2++) ans.push_back(nums2[idx2]);

        nums1 = ans;
    }
};