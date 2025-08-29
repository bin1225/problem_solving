#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<bool> isrow(matrix.size(), false);
        vector<bool> iscol(matrix[0].size(), false);
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j]==0) {
                    isrow[i] = true;
                    iscol[j] = true;
                }
            }
        }

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(isrow[i]|| iscol[j]) matrix[i][j] = 0;
                }
        }
    }
};