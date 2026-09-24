#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Map[26][26];
bool visited[26][26];

vector<int> answer;

int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int dfs(int y, int x) {
    
    int result = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||ny>=N||nx<0||nx>=N) continue;
        if(visited[ny][nx]||Map[ny][nx]==0) continue;
        visited[ny][nx] = true;
        result+=dfs(ny,nx);
    }
    return result;
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>Map[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j] || Map[i][j]==0) continue;
            visited[i][j] = true;
            answer.push_back(dfs(i,j));
        }
    }
    
    sort(answer.begin(), answer.end());
    cout<<answer.size()<<endl;
    for(int a: answer) cout<<a<<endl;
    return 0;
}