#include <iostream>
using namespace std;

int A[101][101];
int N, M;
bool countRow(int y) {
    int cnt = 1;
    int result = 1;
    for(int i=1; i<N; i++) {
        if(A[y][i-1] == A[y][i]) cnt++;
        else cnt = 1;

        result = max(result, cnt);
    }
    return result >= M;
}

bool countCol(int x) {
    int cnt = 1;
    int result = 1;
    for(int i=1; i<N; i++) {
        if(A[i-1][x] == A[i][x]) cnt++;
        else cnt = 1;
        
        result = max(result, cnt);
    }
    return result >= M;
}

int main() {
    cin>>N>>M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }

    int answer = 0;
    for(int i=0; i<N; i++) {
        answer += countRow(i);
        answer += countCol(i);
    }

    cout<<answer;
    return 0;
}