#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string map[n];
    queue<pair<int,int>> monsters;
    queue<pair<int,int>> q;
    
    vector<vector<int>> monster_dist(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 'M') {
                monster_dist[i][j] = 0; // Initialize monster position with distance 0
                monsters.push({i,j});
            }
            else if(map[i][j] == 'A') {
                q.push({i,j});
            }
        }
    }
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!monsters.empty()) {
        auto [y, x] = monsters.front(); monsters.pop();
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (map[ny][nx] == '#' || monster_dist[ny][nx] != INT_MAX) continue;
            monster_dist[ny][nx] = monster_dist[y][x] + 1;
            monsters.push({ny, nx});
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<vector<int>> path(n, vector<int>(m, 0));
    visited[q.front().first][q.front().second] = 0;
    path[q.front().first][q.front().second] = -1; // Starting point has no direction
    while(!q.empty()) {
        pair<int,int> now = q.front();
        q.pop();
        int x = now.second;
        int y = now.first;
        if(y == 0 || y == n - 1 || x == 0 || x == m - 1) {
            cout << "YES" <<"\n"<< visited[y][x]<< "\n";
            int cur_y = y;
            int cur_x = x;
            vector<string> ans;
            while(path[cur_y][cur_x] != -1) {
                if(path[cur_y][cur_x] == 0) {
                    ans.push_back("R");
                    cur_x--;
                }
                else if(path[cur_y][cur_x] == 1) {
                    ans.push_back("L");
                    cur_x++;
                } 
                else if(path[cur_y][cur_x] == 2) {
                    ans.push_back("D");
                    cur_y--;
                } 
                else if(path[cur_y][cur_x] == 3) {
                    ans.push_back("U");
                    cur_y++;
                }
            }
            reverse(ans.begin(), ans.end());
            for(string s: ans) {
                cout << s;
            }
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0|| ny<0||nx>=m||ny>=n || map[ny][nx] == '#') continue;
            if (visited[ny][nx] != -1) continue;
            if (visited[y][x] + 1 >= monster_dist[ny][nx]) continue; // 안전 체크
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            path[ny][nx] = i;
        }
    }


        cout << "NO";

    return 0;
}