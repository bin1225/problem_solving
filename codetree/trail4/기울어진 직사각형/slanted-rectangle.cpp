#include <iostream>
using namespace std;

int N, answer;
int A[22][22];

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1};

int findMaxSum(int startY, int startX, int dir, int y, int x, int sum) {
    if(dir>=4 || y < 0 || x < 0 || y >= N || x >= N) {
        return 0;
    }
    
    if(y==startY && x==startX && dir!=0) {
        return sum;
    }
    
    int current = A[y][x];

    //방향 유지
    int a = findMaxSum(startY, startX, dir, y+dy[dir], x+dx[dir], sum+current);
    //방향 전환
    int b = findMaxSum(startY, startX, dir+1, y+dy[dir+1], x+dx[dir+1], sum+current);

    return max(a,b);
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            answer = max(answer, findMaxSum(i,j,0,i,j,0));
        }
    }
    
    cout<<answer;
    return 0;
}