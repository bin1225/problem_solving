#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N, M; cin>>N>>M;

    int arr[N+1][M+1];
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i = 1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            arr[i][j] += arr[i-1][j];
        }
    }

    int K; cin>>K;
    int si, sj, ei, ej;
    for(int i=0; i<K; i++) {
        cin>>si>>sj>>ei>>ej;
        int sum = 0;
        for(int j=sj; j<=ej; j++) {
            sum +=arr[ei][j] - arr[si-1][j]; 
        }
        cout<<sum<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}