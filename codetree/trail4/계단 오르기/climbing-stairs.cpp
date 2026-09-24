#include <iostream>
using namespace std;

int dp[1010];
int N;

int main() {
    cin>>N;
    dp[0] = 1;
    for(int i=0; i<=N; i++) {

        for(int j=2; j<=3; j++) {
            if(i+j > N) continue;
            dp[i+j] += dp[i];
            dp[i+j] %= 10007; 
        }
    }

    cout<<dp[N];
    return 0;
}