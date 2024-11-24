#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

ll A[101010];
ll PS[101010];

void Solve() {
    int N; cin>>N;
    for(int i=1; i<=N; i++) cin>>A[i];

    for(int i=1; i<=N; i++){
        PS[i] = PS[i-1]+A[i];
    }

    ll ans=0;
    for(int i=1; i<=N; i++){
        ans+=(PS[N]-PS[i])*A[i];
    }

    cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}