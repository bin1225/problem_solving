#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// y방향, x방향
vector<vector<pair<int, int>>> types = {
	{},
	{{0, 1}, {1, 0}, {-1, 0}, {0, -1}},
	{{-1, 0}, {1, 0}},
	{{0, 1}, {0, -1}},
	{{-1, 0}, {0, 1}},
	{{1, 0}, {0, 1}},
	{{1, 0}, {0, -1}},
	{{-1, 0}, {0, -1}}};

bool check(int dy, int dx, int ny, int nx, int map[55][55])
{
	int type = map[ny][nx];
	if (dy == 0 && dx == 1) // 오른쪽
		return type == 1 || type == 3 || type == 6 || type == 7;
	else if (dy == 1 && dx == 0) // 아래
		return type == 1 || type == 2 || type == 4 || type == 7;
	else if (dy == 0 && dx == -1) // 왼쪽
		return type == 1 || type == 3 || type == 4 || type == 5;
	else if (dy == -1 && dx == 0) // 위
		return type == 1 || type == 2 || type == 5 || type == 6;
	return false;
}
int Solve()
{
	int N, M, R, C, L;
	cin >> N >> M >> R >> C >> L;

	int map[55][55];
	memset(map, 0, sizeof(map));
	bool visited[55][55];
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}

	queue<pair<int, int>> Q;
	Q.push({R, C});
	int answer = 1;
	visited[R][C] = true;
	while (--L > 0 && !Q.empty())
	{
		int size = Q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> pos = Q.front();
			Q.pop();
			// cout << "y:" << pos.first << "  x:" << pos.second << "  type:" << map[pos.first][pos.second] << endl;
			vector<pair<int, int>> dir = types[map[pos.first][pos.second]];
			for (int j = 0; j < dir.size(); j++)
			{
				int ny = pos.first + dir[j].first;
				int nx = pos.second + dir[j].second;
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (map[ny][nx] == 0 || visited[ny][nx])
					continue;
				if (check(dir[j].first, dir[j].second, ny, nx, map) == false)
					continue;
				visited[ny][nx] = true;
				answer++;
				Q.push({ny, nx});
			}
		}
	}
	return answer;
}

int main(int argc, char **argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << Solve() << endl;
	}
	return 0;
}