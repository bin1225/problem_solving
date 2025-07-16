#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int, int>> answer;
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        q.push(i);
        visited[i] = 1;
        if(i!=1) answer.push_back({1, i});

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for(int neighbor : graph[current]) {
                if (visited[neighbor])
                    continue;
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    cout<< answer.size() << "\n";
    for (auto &p : answer) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}