#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    int dp[n][n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if(s[j]=='.') dp[i][j] = 0; 
            else dp[i][j] = -1; //if trap exists
        }
    }

    if(dp[0][0] == -1 || dp[n-1][n-1] == -1) {
        cout << 0 << "\n"; // If start or end is a trap, no paths
        return 0;
    }
    
    dp[0][0] = 1; // Starting point
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) {
            if(dp[i][j] == -1)
                continue;
            if(i-1>=0 && dp[i-1][j] > 0) dp[i][j] += dp[i-1][j]; // from top
            if(j-1>=0 && dp[i][j-1] > 0) dp[i][j] += dp[i][j-1]; // from left
            dp[i][j] %= 1000000007; 
        }   
    }


    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}