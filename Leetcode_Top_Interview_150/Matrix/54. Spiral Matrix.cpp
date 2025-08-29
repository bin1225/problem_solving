#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        int x=0, y=0, dir=0;
        int row = matrix.size(); 
        int col = matrix[0].size();
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(answer.size() < row*col) {
            answer.push_back(matrix[y][x]);
            matrix[y][x] = -101;

            int nx = x+dx[dir], ny = y+dy[dir];
            if(nx < 0 || nx >= col || ny < 0 || ny >= row || matrix[ny][nx]==-101) dir= (dir+1)%4;
            y+=dy[dir];
            x+=dx[dir];
        }

        return answer;
    }
};