#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    if(a[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1; // If the first element is 0, all positions are valid
        }
    } else {
        dp[0][a[0]] = 1; // If the first element is not 0, only that position is valid
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i] == j || a[i] == 0) {
                dp[i][j] = ((ll)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans+=dp[n-1][i];
        ans %= MOD; 
    }

    cout << ans;

    return 0;
}