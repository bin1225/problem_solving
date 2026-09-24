#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    int C, N;
    cin >> C >> N;

    int dp[22][1111]; //i번째까지 고려했을 때 j를 만드는 최소 비용
    memset(dp, 10101010, sizeof(dp));

    int co, val;
    cin >> co >> val;
    for(int i=0; i<=C+100; i++) {
        if(i % val == 0) {
            dp[0][i] = co * (i / val);
        }
    }

    for (int i = 1; i < N; i++)
    {
        cin >> co >> val;
        dp[i][0] = 0;
        for (int j = 0; j <= C+100; j++) {
            if (j - val >= 0)
                dp[i][j] = min(dp[i][j - val] + co, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int answer = INT_MAX;
    for (int i = C; i <= C + 100; i++) {
        answer = min(answer, dp[N - 1][i]);
    }
    cout << answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}