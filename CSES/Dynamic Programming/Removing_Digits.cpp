#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve(int dp[], int n, int cnt) {
    if(n<0)
        return;
    dp[n] = min(dp[n], cnt);
    int tmp = n;
    int digit = 0;
    while(tmp>0) {
        digit = max(digit, tmp % 10);
        tmp /= 10;
    }

    if(dp[n-digit] > cnt + 1) {
        solve(dp, n - digit, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int dp[n+1];
    fill(dp, dp + n + 1, INT_MAX);
    solve(dp, n, 0);

    cout << dp[0] << "\n";
    return 0;
}
