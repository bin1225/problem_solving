#include <iostream>
using namespace std;

int N, answer;
int A[5][5];
int D[5][5];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>D[i][j];
        }
    }
}

void dfs(int y, int x, int cnt) {
    answer = max(answer, cnt);
    int yy = y; int xx = x;
    int dir = D[y][x] -  1;
    while(yy>=0 && yy <N && xx>=0 && xx <N) {
        if(A[yy][xx] > A[y][x]) dfs(yy, xx, cnt+1);
        yy+=dy[dir]; xx += dx[dir];
    }
}
int main() {
    cin>>N;
    init();

    int r, c;
    cin>>r>>c;
    dfs(r-1,c-1,0);
    cout<<answer;
    return 0;
}