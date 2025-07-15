#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Info {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string map[n];
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 'A') start = {i, j};
            if(map[i][j] == 'B') end = {i, j}; 
        }
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    queue<Info> q; 
    q.push({start.second, start.first});
    while(!q.empty()) {
        Info current = q.front();
        q.pop();
        if(current.y == end.first && current.x == end.second) {
            string path = "";
            pair<int, int> pos = {current.y, current.x};
            while(pos != start) {
                char direction = map[pos.first][pos.second];
                path += direction;
                if(direction == 'R') pos.second--;
                else if(direction == 'D') pos.first--;
                else if(direction == 'L') pos.second++;
                else if(direction == 'U') pos.first++;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            if(current.x + dx[i] < 0 || current.x + dx[i] >= m || current.y + dy[i] < 0 || current.y + dy[i] >= n) continue;
            if(map[current.y + dy[i]][current.x + dx[i]] != '.' && map[current.y + dy[i]][current.x + dx[i]] != 'B')    
                continue;

            map[current.y + dy[i]][current.x + dx[i]] = (i == 0 ? 'R' : (i == 1 ? 'D' : (i == 2 ? 'L' : 'U')));

            q.push({current.x + dx[i], current.y + dy[i]});
        }
    }

    cout<< "NO\n";
    return 0;
}