#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

bool Slp[5050];
bool Chk[5050];
int PF[5050];

void Solve() {

    int N,K,Q,M; cin>>N>>K>>Q>>M;
    int n,tmp;
    for(int i=0; i<K; i++){
        cin>>n; Slp[n]=true;
    }

    for(int i=0; i<Q; i++){
        cin>>n; if(Slp[n]) continue;
        tmp = n; 
        while(tmp<=N+2){
            if(!Slp[tmp]) Chk[tmp]=true;
            tmp+=n;
        }
    }

    for(int i=3; i<=N+2; i++){
        if(Chk[i]==false) PF[i] = PF[i-1] + 1;
        else PF[i] = PF[i-1];
    }

    int s,e;
    vector<int> ans;
    for(int i=0; i<M; i++){
        cin>>s>>e;
        ans.push_back(PF[e]-PF[s-1]);
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