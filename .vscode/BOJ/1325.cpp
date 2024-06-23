#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, M, maxNum;
int cnt[10101];
bool visited[10101];
vector<int> G[10101];

int dfs(int n){

    int childCnt = 0;
    visited[n] = true;
    for(int i=0; i<G[n].size(); i++){
        if(!visited[G[n][i]]) {
            childCnt += dfs(G[n][i]);
            visited[G[n][i]] = true;
        }
    }

    return childCnt+1; 
}
void Solve() {
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        G[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        fill(visited, visited+N+1, false);
        cnt[i] = dfs(i);
        maxNum = max(maxNum, cnt[i]);
    }

    for(int i=1; i<=N; i++){
        if(cnt[i] == maxNum) cout<<i<<" ";
        //cout<<cnt[i]<<" ";
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}