#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N; cin>>N;

    int dp[11]; 
    fill(dp, dp+N, 12);
    dp[0] = 0;

    vector<int> jumps;
    for(int i=0; i<N; i++) {
        int num; cin>>num;
        jumps.push_back(num);
    }

    for(int i=0; i<N; i++) {
        for(int j=1; j<=jumps[i]; j++) {
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }

    if(dp[N-1] == 12) cout<<-1;
    else cout<<dp[N-1];
    return 0;
}