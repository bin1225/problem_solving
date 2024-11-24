#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

vector<vector<int>> V;

bool chk(int a, int b){
    for(int i=0; i<V[a].size(); i++) if(V[a][i]==b) return false;
    for(int i=0; i<V[b].size(); i++) if(V[b][i]==a) return false;
    return true;
}
void Solve() {
    int N,M; cin>>N>>M;
    int a,b;
    int answer=0;

    V.resize(N+1);

    for(int i=0; i<M; i++){
        cin>>a>>b;
        V[a].push_back(b);
    }

    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            for(int k=j+1; k<=N; k++){
                if(chk(i,j)&&chk(i,k)&&chk(j,k)) answer++;
            }
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