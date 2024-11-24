#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,M;
vector<int> V[33];

void Solve() {
    cin>>N>>M;
    int tmp;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin>>tmp;
            V[i].push_back(tmp);
        }
    }

    int ans=0;
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++){
            for(int k=j+1; k<M; k++){
                tmp = 0;
                for(int p=0; p<N; p++){
                    tmp+=max(V[p][i],max(V[p][j],V[p][k]));
                }
                ans = max(ans,tmp);
            }
        }
    }

    cout<<ans;
}   


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}