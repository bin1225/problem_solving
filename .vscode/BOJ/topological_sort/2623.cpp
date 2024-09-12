#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,M;
int BF[1010];
vector<int> G[1010];
void Solve() {
    cin>>N>>M;
    int cnt,bf,n;
    for(int i=0; i<M; i++){
        cin>>cnt>>bf;
        for(int j=0; j<cnt-1; j++){
            cin>>n;
            G[bf].push_back(n); BF[n]++;
            bf = n;
        }
    }

    queue<int> Q;
    vector<int> ANS;
    for(int i=1; i<=N; i++){
        if(BF[i]==0) Q.push(i);
    }
    
    while(!Q.empty()){
        n = Q.front(); Q.pop(); ANS.push_back(n);

        for(int i=0; i<G[n].size(); i++){
            if(--BF[G[n][i]]==0) Q.push(G[n][i]);
        }
    }
    
    if(ANS.size()!=N) cout<<0;
    else{
        for(int a: ANS) cout<<a<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}