#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int dp[s1.size() + 1][s2.size() + 1];

    for (int i = 0; i<= s1.size(); i++) {
        dp[i][0] = i; // Deleting all characters from s1
    }
    for(int j = 0; j <= s2.size(); j++) {
        dp[0][j] = j; // Inserting all characters from s2
    }

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    cout << dp[s1.size()][s2.size()];
    return 0;
}