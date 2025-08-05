#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Edge {
    int from, to;
    ll weigh;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<int> parent(n+1);
    vector<ll> dist(n+1, 0);
    dist[1] = 0;
    parent[1] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < edges.size(); j++) {
            auto edge = edges[j];
            if(dist[edge.from]!= LONG_LONG_MAX && dist[edge.to] > dist[edge.from] + edge.weigh) {
                parent[edge.to] = edge.from;
                dist[edge.to] = dist[edge.from] + edge.weigh;
                if(i==n) {
                    
                    int x = edge.from;
                    for (int i = 0; i < n; ++i) {
                        x = parent[x];
                    }
                    cout << "YES"<<"\n";
                    vector<int> path;
                    int now = x;
                    do {
                        path.push_back(now);
                        now = parent[now];
                    } while (now != x);
                    path.push_back(now);
                    reverse(path.begin(), path.end());

                    for(auto p: path) {
                        cout << p << " ";
                    }
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
