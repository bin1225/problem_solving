#include <bits/stdc++.h>

class Solution {
public:
    queue<pair<int,int>> Q;
    int visited[202][202];
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};

    void bfs(int i, int j, vector<vector<char>>& answer, vector<vector<char>>& board){
        
        Q.push({i,j});
        visited[i][j] = 1;
        int x,y,xx,yy;
        while(!Q.empty()){
            x = Q.front().second; y = Q.front().first;
            Q.pop();
            
            for(int i=0; i<4; i++){
                yy = y+dy[i]; xx= x+dx[i];
                if(yy<0||yy>=answer.size()||xx<0||xx>=answer[0].size()) continue;
                if(visited[yy][xx] == 1 || board[yy][xx] == 'X') continue;
                
                visited[yy][xx] = 1; answer[yy][xx] = 'O';
                Q.push({yy,xx});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        vector<vector<char>> answer;
        
        for(int i=0; i<board.size(); i++){
            vector<char> V;
            for(int j=0; j<board[i].size(); j++){
                V.push_back('X');
            }
            answer.push_back(V);
        }
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(i!=0&&j!=0&& i!=board.size()-1 && j!=board[0].size()-1) continue;
                if(visited[i][j] == 0 && board[i][j] == 'O') {
                    answer[i][j] = 'O';
                    bfs(i,j,answer, board);
                }
            }
        }
        
        board = answer;
    }
};