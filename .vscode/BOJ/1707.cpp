#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int T, V, E;
int visited[20202];
vector<int> G[20202];

bool bfs(int n){
    int now, next;
    queue<int> Q;
    Q.push(n);
    visited[n] = 1;
    
    while(!Q.empty()){
        now = Q.front(); Q.pop();

        for(int i=0; i<G[now].size(); i++){
            next = G[now][i];
            if(visited[next] == visited[now]) return false;
            else if(visited[next] == 0){
                if(visited[now]==1) visited[next]=2;
                else visited[next] = 1; 
                Q.push(next);
            }
        }
    }

    return true;
}

void Solve() {
    cin>>V>>E;
    fill(visited, visited+V+1, 0);
    for(int i=0; i<=V; i++) G[i].clear();

    int a, b;
    for(int i=0; i<E; i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1; i<=V; i++){
        if(visited[i]==0) {
            if(!bfs(i)) {
            cout<<"NO"<<endl;
            return;
        }
        }
 
    }
    cout<<"YES"<<endl;
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T-->0){
        Solve();
    }
    return 0;
}