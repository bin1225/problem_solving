#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> price;
    vector<int> page;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        price.push_back(p);
    }

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        page.push_back(p);
    }

    int dp[x + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if(j - price[i] >= 0) {
                dp[j] = max(dp[j - price[i]] + page[i], dp[j]);
            }
        }
    }

    cout << dp[x];

    return 0;
}