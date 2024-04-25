#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define divide 1000000009
using namespace std;

int N;
int dp[1010101];

void Solve() {
    cin>>N;

    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i=4; i<=N; i++){
        dp[i] = ((dp[i-1] + dp[i-2])% divide + dp[i-3]) % divide;
    }

    cout<<dp[N]<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T-->0) Solve();

    return 0;
}