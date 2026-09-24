#include <iostream>
using namespace std;

int N, M;
int A[22][22];

bool checkAvailable(int x1, int y1, int x2, int y2) {
    
    for(int i=y1; i<=y2; i++) {
        for(int j=x1; j<=x2; j++) {
            if(A[i][j] <= 0) return false;
        }
    }
    return true;
}

int main() {
    // Please write your code here.

    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>A[i][j];
        }
    }

    int answer = -1;
    for(int y1=0; y1<N; y1++) {
        for(int x1=0; x1<M; x1++) {
            for(int y2=y1; y2<N; y2++) {
                for(int x2=x1; x2<M; x2++) {
                    if(checkAvailable(x1,y1,x2,y2)) {
                        answer = max(answer, (y2-y1+1) * (x2-x1+1));
                    }
                }
            }
        }
    }
    cout<<answer;
    return 0;
}