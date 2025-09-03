#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++) {
            int j = i;
            int end = intervals[i][1];
            while(j+1<n && end >= intervals[j+1][0]) {
                end = max(end, intervals[j+1][1]);
                j++;
            }
            answer.push_back({intervals[i][0], end});
            i = j;
        }
        return answer;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
//         vector<vector<int>> answer;
//         sort(intervals.begin(), intervals.end());
//         vector<int> prev = intervals[0];
//         for(int i=1; i<intervals.size(); i++) {
            
//             vector<int> interval = intervals[i];

//             if(interval[0] <= prev[1]) {
//                 prev[1] = max(prev[1], interval[1]);
//             }
//             else {
//                 answer.push_back(prev);
//                 prev = interval;
//             }
//         }
//         answer.push_back(prev);
//         return answer;
//     }
// };