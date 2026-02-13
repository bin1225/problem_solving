#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N, M;
vector<string> board;
int flag[1010][1010];
int flag_value = 1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
unordered_map<int, int> cnt;

void dfs(int y, int x) {
    queue<pair<int, int>> Q;
    flag[y][x] = flag_value;
    Q.push({y, x});
    int result = 1;
    while(!Q.empty()) {
        int cur_x = Q.front().second;
        int cur_y = Q.front().first;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N || flag[next_y][next_x])
                continue;
            if(board[next_y][next_x] == '1')
                continue;
            Q.push({next_y, next_x});
            flag[next_y][next_x] = flag_value;
            result++;
        }
    }
    cnt[flag_value] = result;
    flag_value++;
}

void Solve() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(board[i][j] == '0' && flag[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    vector<string> answer;
    for (int i = 0; i < N; i++) {
        string s;
        for (int j = 0; j < M; j++) {
            if(board[i][j] == '1') {
                int tmp = 1;
                set<int> S;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny<0 || nx<0 || ny >=N || nx>=M)
                        continue;
                    S.insert(flag[ny][nx]);
                }
                for(auto a: S) {
                    tmp += cnt[a];
                }
                tmp %= 10;
                s += to_string(tmp);
            }
            else
                s += "0";
        }
        answer.push_back(s);
    }

    for(auto a: answer)
        cout << a << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}