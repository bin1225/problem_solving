#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, answer;
int A[1010];
int DP[1010][2];
void Solve() {

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    fill(&DP[0][0], &DP[N][1], 1);
    for(int i=0; i<N; i++){

        for(int j=0; j<i; j++){
            if(A[j]<A[i]) DP[i][0] = max(DP[i][0], DP[j][0]+1);
        }
    }

    for(int i=N-1; i>=0; i--){

        for(int j=N-1; j>i; j--){
            if(A[j]<A[i]) DP[i][1] = max(DP[i][1], DP[j][1]+1);
        }
    }

    for(int i=0; i<N; i++){
        answer = max(answer, DP[i][0]+DP[i][1]-1);
    }

    cout<<answer;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}