/*
    time: 40min 
    success: false
    note: 단일 for문 내에서 모든 경우를 고려하려다 보니 복잡해져서 정확히 조건을 못 만들어낸 것 같다. 
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        int idx = 0;
        while(idx<n && intervals[idx][1] < newInterval[0]) {
            ans.push_back(intervals[idx]);
            idx++;
        }

        while(idx<n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }

        ans.push_back(newInterval);
        while(idx<n) {
            ans.push_back(intervals[idx]); idx++;
        }

        return ans;
    }
};