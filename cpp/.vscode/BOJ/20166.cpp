#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 

#define endl "\n"

using namespace std;

int N, M, K;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
string Map[13][13];
map<string, int> Hash;

void dfs(int y, int x, string s){
    int yy, xx;

    if(s.size() > 5){
        return;
    }
    Hash[s]++;

    for(int i=0; i<8; i++){
        yy = y+dy[i]; xx = x+dx[i];
        if(yy>N) yy = 1;
        if(xx>M) xx = 1;
        if(yy<1) yy = N;
        if(xx<1) xx = M;
        dfs(yy, xx, s+Map[yy][xx]);
    }
}

void Solve() {
    string input;

    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        cin>>input;
        for(int j=1; j<=M; j++){
            Map[i][j] = input[j-1];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dfs(i,j,Map[i][j]);
        }
    }

    for(int i=0; i<K; i++){
        cin>>input;
        cout<<Hash[input]<<endl;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}