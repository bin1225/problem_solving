#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    vector<ll> visited(n + 1, LONG_LONG_MAX);
    visited[1] = 0;
    int count = 0;
    while(!pq.empty()) {
        ll w = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now] < w)
            continue;
            
        for(auto next : graph[now]) {
            if(visited[next.first] > w + next.second) {
                visited[next.first] = w + next.second;
                pq.push({w + next.second, next.first});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << " ";
    }
    
    return 0;
}