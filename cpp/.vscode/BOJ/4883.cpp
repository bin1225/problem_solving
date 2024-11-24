#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define ll long long
using namespace std;

int N;
int dp[101010][3];

int Solve(int N) {
    
    int a, b, c;
    cin>>a>>b>>c;
    dp[1][0] = 1010101; dp[1][1] = b; dp[1][2] = b+c;
    for(int i=2; i<=N; i++){    
        cin>>a>>b>>c;

        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a;
        dp[i][1] = min(min(dp[i][0], dp[i-1][0]), min(dp[i-1][1],dp[i-1][2])) + b;
        dp[i][2] = min(min(dp[i][1], dp[i-1][1]), dp[i-1][2]) + c;
    }
    return dp[N][1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;

    while(true){
        cin>>N; if(N==0) break;
        int result = Solve(N);
        cout<<T<<". " << result<<endl;
        T++;
    }

    return 0;
}