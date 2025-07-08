#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        coins.push_back(a);
    }

    ll dp[x+1];
    fill(dp, dp+x+1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if(i-coins[j] >=0) {
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    if(dp[x] == INT_MAX)
        cout << -1;
    else
        cout << dp[x];
    return 0;
}