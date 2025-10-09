#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
char dir[4] = {'d', 'l', 'r', 'u'};

string answer = "";
bool found = false;

void dfs(int n, int m, int y, int x, int r, int c, int k, string path) {
    if (found) return;  // 이미 정답 찾으면 중단
    
    // 남은 거리와 남은 이동 횟수 계산
    int dist = abs(r - y) + abs(c - x);
    if (dist > k - (int)path.size()) return;  // 남은 걸음으로 도달 불가능
    if (((k - path.size()) - dist) % 2 != 0) return; // parity check

    // 종료 조건
    if ((int)path.size() == k) {
        if (y == r && x == c) {
            answer = path;
            found = true;  // 첫 번째 사전순 정답이면 끝
        }
        return;
    }

    // 사전순 우선 탐색
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
        dfs(n, m, ny, nx, r, c, k, path + dir[i]);
        if (found) return;  // 찾으면 바로 종료
    }
}

string solution(int n, int m, int y, int x, int r, int c, int k) {
    int dist = abs(r - y) + abs(c - x);
    if (dist > k || (k - dist) % 2 != 0) return "impossible";
    dfs(n, m, y, x, r, c, k, "");
    return answer.empty() ? "impossible" : answer;
}
