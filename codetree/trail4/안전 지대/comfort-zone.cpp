#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int Map[101][101];
bool visited[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int y, int x, int k) {

    for(int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny<0||nx<0||ny>=N||nx>=M) continue;
        if(visited[ny][nx] || Map[ny][nx] <= k) continue;

        visited[ny][nx] = true;
        dfs(ny,nx,k);
    }
}

int main() {

    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>Map[i][j];
        }
    }

    int answer_count = 0; 
    int answer_height = 1;

    for(int K=1; K<=101; K++) {
        int count = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[i][j] || Map[i][j]<=K) continue;
                    visited[i][j] = true;
                    count++;
                    dfs(i,j,K);
            }  
        }
        if(count > answer_count) {
            answer_count = count;
            answer_height = K;
        }
        memset(visited, false, sizeof(visited));
    }

    cout<<answer_height<<" "<<answer_count;
    return 0;
}