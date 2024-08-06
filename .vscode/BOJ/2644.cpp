#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N,A,B,M;
vector<int> G[101];
int dist[101];
queue<int> Q;
void Solve() {
    cin>>N>>A>>B>>M;

    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(dist, dist+N+1, -1);
    Q.push(A);
    dist[A] = 0;

    int now;
    while(!Q.empty()){
        now = Q.front(); Q.pop();

        for(int i=0; i<G[now].size(); i++){
            if(dist[G[now][i]]>=0) continue;
            
            dist[G[now][i]] = dist[now]+1;
            Q.push(G[now][i]);
        }
    }

    cout<<dist[B];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}