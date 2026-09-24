#include <iostream>
using namespace std;

int N;
int A[22][22];

int countCoinInArea(int y, int x) {
    int cnt = 0;
    for(int i=y; i<y+3; i++) {
        for(int j=x; j<x+3; j++) {
            cnt += A[i][j];
        }
    }
    return cnt;
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }

    int answer = 0;
    for(int i=0; i+3<=N; i++) {
        for(int j=0; j+3<=N; j++) {
            answer = max(answer, countCoinInArea(i,j));
        }
    }

    cout<<answer;
    return 0;
}