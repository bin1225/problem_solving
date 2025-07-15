#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string map[n];
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int room_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<m; j++) {
            if(map[i][j] == '.') {
                queue<pair<int, int>> q;
                q.push({i, j});
                map[i][j] = '#'; // Mark as visited
                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        if(y+dy[k] <0 || y+dy[k] > n-1 || x+dx[k] < 0 || x+dx[k] > m-1) continue;
                        if(map[y+dy[k]][x+dx[k]] == '.') {
                            map[y+dy[k]][x+dx[k]] = '#'; // Mark as visited
                            q.push({y + dy[k], x + dx[k]});
                        }
                    }
                }
                room_count++;
            }
        }
    }

    cout << room_count << "\n";
    return 0;
}