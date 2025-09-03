#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkNeighbor(int y, int x, int wide, int height, vector<vector<int>>& board) {
        int dx[] = {1,0,-1,0,1,1,-1,-1};
        int dy[] = {0,1,0,-1,1,-1,1,-1};

        int liveCnt=0;
        for(int i=0; i<8; i++) {
            int nx,ny;
            nx = x+dx[i]; ny = y+dy[i];
            if(nx<0||ny<0||nx>=wide||ny>=height) continue;
            if(board[ny][nx] & 1) liveCnt++;
        }
        return liveCnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int wide = board[0].size();
        int height = board.size();

        for(int i=0; i<height; i++) {
            for(int j=0; j<wide; j++) {
                int liveCnt = checkNeighbor(i,j,wide,height,board);
                if((board[i][j] & 1) && (liveCnt==2||liveCnt==3)) board[i][j] |= 2;
                else if(!(board[i][j] & 1) && liveCnt == 3) board[i][j] |= 2;
            }
        }
        for(int i=0; i<height; i++) {
            for(int j=0; j<wide; j++) {
                board[i][j]>>=1;
            }
        }
    }
};