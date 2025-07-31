#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr1(n+1);
    vector<int> arr2(m+1);
    for (int i = 1; i<=n; i++)
        cin >> arr1[i];
    for (int j = 1; j <= m; j++)
        cin >> arr2[j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m; j++) {
            if(arr1[i] == arr2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int cnt = dp[n][m];
    int a, b;
    a = n;
    b = m;
    vector<int> ans;
    while(cnt>0) {
        if(arr1[a] == arr2[b]) {
            ans.push_back(arr1[a]);
            cnt--;
            a--;
            b--;
        }
        else {
            if(dp[a-1][b] > dp[a][b-1])
                a--;
            else
                b--;
        }
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(int k: ans) {
        cout << k << " ";
    }
    return 0;
}