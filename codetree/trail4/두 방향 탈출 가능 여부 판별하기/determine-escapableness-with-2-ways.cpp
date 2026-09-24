#include <iostream>
using namespace std;

int N, M;
int Map[101][101];
bool visited[101][101];

int dx[] = {0,1};
int dy[] = {1,0};

int success;

void dfs(int y, int x) {
    if(y==N-1 && x ==M-1) {
        success = true;
        return;
    }
    
    for(int i=0; i<2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||ny>=N||nx<0||nx>=M) continue;
        if(Map[ny][nx] == 0 || visited[ny][nx]) continue;

        visited[ny][nx] = true;
        dfs(ny,nx);
    }
}

int main() {

    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>Map[i][j];
        }
    }

    dfs(0,0);
    cout<<success;
    return 0;
}