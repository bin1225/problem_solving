/*
    time: 10min 
    success: true
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int range = points[0][1];
        int answer = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=range) {
                range = min(range, points[i][1]);
            }
            else {
                answer++;
                range = points[i][1];
            }
        }
        return answer;
    }
};