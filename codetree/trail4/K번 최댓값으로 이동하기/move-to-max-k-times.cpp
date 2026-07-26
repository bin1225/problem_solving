#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, K;
int Map[101][101];
bool visited[101][101];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

pair<int,int> next_p;
int next_num;

bool canGo(int ny, int nx) {
    if(ny<0||nx<0||ny>=N||nx>=N) return false;
    if(visited[ny][nx]) return false;
    return true;
}

void updateNext(int y, int x){
    if(Map[y][x] > next_num){
        next_num = Map[y][x];
        next_p = {y,x};
    }
    else if(Map[y][x] == next_num){
        if(make_pair(y,x) < next_p)
            next_p = {y,x};
    }
}

void dfs(int r, int c) {
    queue<pair<int,int>> Q;
    Q.push({r,c});
    visited[r][c] = true;
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!canGo(ny, nx)) continue;
            if(Map[ny][nx] >= Map[r][c]) continue;
            visited[ny][nx] = true;
            updateNext(ny,nx);
            Q.push({ny,nx});
        }
    }
    
}

int main() {
    cin>>N>>K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>Map[i][j];
        }
    }

    int r,c;
    cin>>r>>c;
    next_p = {r-1,c-1};
    for(int i=0; i<K; i++) {
        memset(visited, false, sizeof(visited));
        visited[next_p.first][next_p.second] = true;
        next_num = 0;
        dfs(next_p.first, next_p.second);
        //cout<<next_p.first+1<<" "<<next_p.second+1<<endl;
    }

    cout<<next_p.first+1<<" "<<next_p.second+1;
    return 0;
}