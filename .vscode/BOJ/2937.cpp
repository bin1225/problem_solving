#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, M, answer;
int A[101][101];
int Prefix[101][101];

void Solve() {
    cin>>N>>M;

    int r, c;
    for(int i=0; i<M; i++){
        cin>>r>>c;
        A[r][c]=1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            Prefix[i][j] = Prefix[i-1][j] + Prefix[i][j-1] - Prefix[i-1][j-1] + A[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int ii, jj;
            for(int k=1; k<=M; k++){
                ii = i+k-1;
                jj = j+M/k-1;
                if(M%k!=0) continue;
                else if(ii>N || jj > N) continue;
                
                int sum = Prefix[ii][jj] - Prefix[ii][j-1] - Prefix[i-1][jj] + Prefix[i-1][j-1];
                answer = max(answer, sum);
            }
        }
    }
    cout<<M-answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}