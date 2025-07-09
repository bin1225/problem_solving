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

    int dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Base case: 1 way to make amount 0 (using no coins)
    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= x; j++) {
            if(j-coins[i] >=0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= 1000000007; // Using modulo to prevent overflow
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}