#include<bits/stdc++.h>

#define ll long long

using namespace std;

void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& visited) {
    

    for(int neighbor : graph[node]) {
        if(visited[neighbor] == 0) {
            visited[neighbor] = node;
            dfs(neighbor, node, graph, visited);
        }
        else if(visited[neighbor] != node && neighbor != parent) {
            // Found a cycle
            vector<int> cycle;
            int current = node;

            while(current != visited[neighbor]) {
                cycle.push_back(current);
                current = visited[current];
            }
            cycle.push_back(node);
            cout << cycle.size() << "\n";
            for(int i = cycle.size() - 1; i >= 0; i--) {
                cout << cycle[i] << " ";
            }
            exit(0);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            visited[i] = -1; // Mark the starting node
            dfs(i, -1, graph, visited);
        }
    }

    
    cout << "IMPOSSIBLE\n";
    return 0;
}