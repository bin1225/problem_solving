#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int A[101010];
int PS[101010];

void Solve() {
    int N; cin>>N;
    for(int i=1; i<=N; i++){
        cin>>A[i];
    }
    A[N+1] = INT_MAX;

    for(int i=1; i<=N; i++){
        PS[i] = PS[i-1];
        if(A[i]>A[i+1]) PS[i]++;
    }
    
    int Q,x,y,cnt; cin>>Q;
    vector<int> ans;
    for(int i=1; i<=Q; i++){
        cin>>x>>y;
        ans.push_back(PS[y-1]-PS[x-1]);
    }

    for(int a: ans) cout<<a<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}