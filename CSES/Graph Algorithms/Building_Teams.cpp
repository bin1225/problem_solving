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
        queue<int> q;
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 0) 
            continue;  // Skip already visited nodes
        q.push(i);
        visited[i] = 1;

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(int neighbor: graph[current]) {
                if(visited[neighbor] == 0) {
                    visited[neighbor] = (visited[current] == 1) ? 2 : 1;
                    q.push(neighbor);
                } else if(visited[neighbor] == visited[current]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        
        }
    }
        
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << " ";
    }
    return 0;
}