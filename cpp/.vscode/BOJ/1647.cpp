#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int N, M, answer, cut;
int visited[101010];
vector<pair<int,int>> G[101010];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;

void Solve() {
    cin>>N>>M;

    int a, b, w;
    for(int i=0; i<M; i++){
        cin>>a>>b>>w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }

    PQ.push({0,1});

    while(!PQ.empty()){
        int now = PQ.top().second; 
        int weight = PQ.top().first;
        PQ.pop();
        if(visited[now] == true) continue;
        cut = max(cut, weight);
        visited[now] = true; answer += weight;

        for(int i=0; i<G[now].size(); i++){
            pair<int,int> next = G[now][i];
            PQ.push({next.second, next.first});
        }
    }

    cout<<answer - cut;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}