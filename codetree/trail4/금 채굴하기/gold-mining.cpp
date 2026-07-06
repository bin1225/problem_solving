#include <iostream>
#include <limits.h>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int grid[22][22];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int calculateMaxValue(int y, int x) {

    int dist[22][22];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    queue<pair<int,int>> Q;
    Q.push({y,x});
    dist[y][x] = 0;
    
    while(!Q.empty()) {
        int ny = Q.front().first;
        int nx = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int nxty = ny + dy[i];
            int nxtx = nx + dx[i];
            if(nxty<0||nxtx<0||nxty>=n||nxtx>=n) continue;
            if(dist[nxty][nxtx]!=INT_MAX) continue;
            dist[nxty][nxtx] = dist[ny][nx] + 1;
            Q.push({nxty, nxtx});
        }
    }

    int result[22]; memset(result, 0, sizeof(result));  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j]==1) {
                int d = dist[i][j];
                result[d]++;
            }
        }
    }

    int maxValue = 0;
    int cnt = 0;
    for(int i=0; i<=n; i++) {
        int cost = i * i + (i+1) * (i+1);
        cnt += result[i];
        if(cnt * m < cost) continue;
        maxValue = max(maxValue, cnt);
    }
    return maxValue;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, calculateMaxValue(i,j));
        }
    }

    cout<<answer;
    return 0;
}
