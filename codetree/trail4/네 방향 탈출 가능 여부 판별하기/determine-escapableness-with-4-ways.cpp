#include <iostream>
#include <queue>

using namespace std;

int N, M;
int Map[101][101];
bool visited[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main() {
    cin>>N>>M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>Map[i][j];
        }
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});
    visited[0][0] = true;
    
    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(visited[ny][nx] || Map[ny][nx] == 0) continue;

            visited[ny][nx] = true;
            Q.push({ny,nx});
        }
    }

    cout<<visited[N-1][M-1];
    return 0;
}