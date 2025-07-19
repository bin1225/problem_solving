#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if(visited[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int current = n;
    int count = 0;
    vector<int> path;
    while (current != 1) {
        path.push_back(current);
        current = visited[current];
        count++;
    }

    cout << count + 1 << "\n";
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (int node : path) {
        cout << node << " ";
    }
    return 0;
}