#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];

int countForBlocks(int y, int x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int base = grid[y][x];
    vector<int> numbers;
    for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
        numbers.push_back(grid[yy][xx]);
    }    
    sort(numbers.begin(), numbers.end(), greater<>());

    return base + numbers[0] + numbers[1];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer = max(answer, countForBlocks(i,j));
        }
    }
    cout<<answer;
    return 0;
}
