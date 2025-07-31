#include<bits/stdc++.h>

#define ll long long
#define INF 1e15
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    vector<vector<pair<int, int>>> Graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
        Graph[b].push_back({a, c});
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }
        return 0;
}