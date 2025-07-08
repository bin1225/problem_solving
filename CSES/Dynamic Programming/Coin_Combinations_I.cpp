#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
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
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Base case: 1 way to make amount 0 (using no coins)
    for (int i = 1; i <= x; i++){
        for(int j: coins) {
            if(i-j>=0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD; 
            }
        }
    }

    cout << dp[x];
    return 0;
}