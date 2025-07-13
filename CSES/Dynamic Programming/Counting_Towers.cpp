#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
using namespace std;

void solve() {

    int h;
    cin >> h;
    ll dp[h][2]; // [i][0] : 경계선을 제거하는 경우, [i][1] : 경계선을 유지하는 경우

    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < h; i++) {
        dp[i][0] = (dp[i - 1][0] * 2 + dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i - 1][1] * 4)%MOD;
        
    }

    cout << (dp[h - 1][0] + dp[h - 1][1])%MOD<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    while(n-->0) {
        solve();
    }

    return 0;
}