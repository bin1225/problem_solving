#include <iostream>
using namespace std;

int N;
int A[22][22];

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
            int cnt = 0;
            for(int y=i; y<i+3; y++) {
                for(int x=j; x<j+3; x++) {
                    cnt += A[y][x];
                }
            }
            answer = max(answer, cnt);
        }
    }

    cout<<answer;
    return 0;
}