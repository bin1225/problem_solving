#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,K; 
bool chk[11];
vector<string> V;
set<string> S;

void dfs(int depth, string s){
    if(depth>=K){
        S.insert(s); return;
    }

    for(int i=0; i<N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        dfs(depth+1, s+V[i]);
        chk[i] = false;
    }
}
void Solve() {
    cin>>N>>K;
    
    int n;
    for(int i=0; i<N; i++){
        cin>>n; V.push_back(to_string(n));
    }

    dfs(0,"");

    cout<<S.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}