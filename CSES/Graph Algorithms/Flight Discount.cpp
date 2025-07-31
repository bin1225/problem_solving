#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Info {
    ll cost;
    bool coupon;
    int node;

    // priority_queue는 기본적으로 max-heap이므로,
    // 오름차순 정렬을 위해 cost가 큰 것이 "작다"고 정의함
    bool operator<(const Info& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    priority_queue<Info> pq;
    vector<vector<ll>> dist(n + 1, vector<ll>(2,LONG_LONG_MAX));
    pq.push({0, false, 1});
    dist[1][0] = 0;
    while(!pq.empty()) {
        Info info = pq.top();
        pq.pop();

        if (dist[info.node][info.coupon] < info.cost) continue;
        for(auto p: graph[info.node]) {
            if(dist[p.first][info.coupon] <= info.cost + p.second)
                continue;
            
            if(info.coupon == false) {
                pq.push({info.cost + p.second / 2, true, p.first});
                dist[p.first][1] = min(dist[p.first][1], info.cost + p.second / 2);
            }
            pq.push({info.cost + p.second, info.coupon, p.first});
            dist[p.first][info.coupon] = min(dist[p.first][info.coupon], info.cost + p.second);
        }
    }

    cout << min(dist[n][1], dist[n][0]);
    return 0;
}