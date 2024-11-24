#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N, M;
int dist[20202];
vector<int> G[20202];
queue<int> Q;

void Solve() {
    cin>>N>>M;
    int a, b, now, next;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(dist, dist+N+1, -1);
    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()){
        now = Q.front(); Q.pop();

        for(int i=0; i<G[now].size(); i++){
            next = G[now][i];
            if(dist[next]>=0) continue;
            dist[next] = dist[now]+1;
            Q.push(next);
        }
    }

    int maxDist=0, cnt=0, maxNum=0;
    for(int i=1; i<=N; i++){
        if(dist[i]>maxDist){
            maxDist = dist[i];
            cnt=1;
            maxNum = i;
        }
        else if(dist[i]==maxDist) cnt++;
    }

    cout<<maxNum<<" "<<maxDist<<" "<<cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}