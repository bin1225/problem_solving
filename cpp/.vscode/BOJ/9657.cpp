#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
int dp[1010];
int tmp[3];
void Solve() {
    cin>>N;

    tmp[0] = 1; tmp[1] = 3; tmp[2] = 4;

    dp[0] = 0; dp[1] = dp[3] = dp[4] = 1;
    for(int i=4; i<=N; i++){
        for(int j=0; j<3; j++){
            if(dp[i-tmp[j]] == 0) dp[i] = 1;
        }
    }

    dp[N] == 1 ? cout<<"SK" : cout<<"CY";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}