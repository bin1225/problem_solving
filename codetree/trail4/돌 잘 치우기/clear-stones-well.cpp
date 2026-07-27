#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, K, M;
int answer;
int Map[101][101];

vector<pair<int,int>> stons;
vector<pair<int,int>> start;
vector<int> selected;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int countAvailableArea() {

    bool visited[101][101];
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> Q;
    for(int i=0; i<start.size(); i++) {
        Q.push(start[i]);
        visited[start[i].first][start[i].second] = true;
    }

    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];

            if(nr<0||nc<0||nr>=N||nc>=N) continue;
            if(visited[nr][nc] || Map[nr][nc] == 1) continue;

            visited[nr][nc] = true;
            Q.push({nr,nc});
        }
    }

    int result = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) result++;
        }
    }

    return result;
}

void choose(int idx) {
    if(selected.size() == M) {
        //돌 제거
        for(int i=0; i<selected.size(); i++) {
            pair<int,int> stoneLocation = stons[selected[i]];
            Map[stoneLocation.first][stoneLocation.second] = 0;
        }
        
        int count = countAvailableArea();
        answer = max(answer, count);
        //돌 다시 놓기
        for(int i=0; i<selected.size(); i++) {
            pair<int,int> stoneLocation = stons[selected[i]];
            Map[stoneLocation.first][stoneLocation.second] = 1;
        }
        return;
    }

    for(int i = idx; i<stons.size(); i++) {
        selected.push_back(i);
        choose(i+1);
        selected.pop_back();
    }
}

int main() {
    cin>>N>>K>>M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>Map[i][j];
            if(Map[i][j] == 1) stons.push_back({i,j});
        }
    }

    for(int i=0; i<K; i++) {
        int r,c; cin>>r>>c;
        start.push_back({r-1,c-1});
    }

    choose(0);
    cout<<answer;
    return 0;
}