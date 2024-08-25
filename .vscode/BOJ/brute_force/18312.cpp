#include<bits/stdc++.h>

#define endl "\n"

using namespace std;

int N,K;

void Solve() {
    cin>>N>>K;
    int h,m,s,answer;

    answer=0;
    for(int i=0; i<=N; i++){
        h=i;
        for(int j=1; j<=3600; j++){
            m = j/60; s = j%60;
            if(h%10==K||h/10==K||m/10==K||m%10==K||s/10==K||s%10==K) answer++;
        }
    }
    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}