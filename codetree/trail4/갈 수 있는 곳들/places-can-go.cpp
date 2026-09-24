#include <iostream>
#include <queue>

using namespace std;

int N, K;
int answer;
int Map[101][101];
bool visited[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int r, int c) {

    queue<pair<int,int>> Q;
    Q.push({r,c});
    visited[r][c] = true; answer++;

    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=N||nx>=N) continue;
            if(visited[ny][nx] || Map[ny][nx]) continue;
            visited[ny][nx] = true;
            answer++;
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
    for(int i=0; i<K; i++) {
        cin>>r>>c;
        if(visited[r-1][c-1]) continue;

        bfs(r-1,c-1);
    }

    cout<<answer;
    return 0;
}