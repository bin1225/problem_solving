#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,M;
bool CHK[101];
int BF[101];
int CNT[101];
vector<pair<int,int>> G[101];

void Solve() {
    cin>>N>>M;
    int x,y,k;
    for(int i=0; i<M; i++){
        cin>>x>>y>>k;
        G[x].push_back({y,k});
        BF[y]++;
        CHK[x] = true;
    }

    queue<int> Q; Q.push(N); CNT[N] = 1;
    vector<int> V;
    for(int i=1; i<=N; i++) if(CHK[i]==false) V.push_back(i);

    int n;
    while(!Q.empty()){
        n = Q.front(); Q.pop();

        for(int i=0; i<G[n].size(); i++){
            CNT[G[n][i].first] += CNT[n] * G[n][i].second;
            if(--BF[G[n][i].first]==0) Q.push(G[n][i].first); 
        }
    }

    for(auto a: V){
        cout<<a<<" "<<CNT[a]<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}