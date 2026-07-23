#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];

vector<vector<int>> graph(1010);
bool visited[1010];
int answer;

void dfs(int node) {

    for(int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if(visited[next]) continue;

        visited[next] = true; 
        answer++;
        dfs(next);
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    // Please write your code here.
    visited[1] = true;
    dfs(1);
    cout<<answer;
    return 0;
}
