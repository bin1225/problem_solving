#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define endl "\n"

using namespace std;

int N, M, answer;
int check[505];
unordered_map<int, vector<int>> G;
queue<pair<int,int>> Q;

void bfs(){
    Q.push({1,0});
    int n, depth;
    while(!Q.empty()){
        n = Q.front().first; depth = Q.front().second; Q.pop();
        if(depth>=2) continue;
        for(int i=0; i<G[n].size(); i++){
            if(check[G[n][i]] == 0){
                check[G[n][i]] = 1;
                answer++;
                Q.push({G[n][i], depth+1});
            }
        }
    }
    
}
void Solve() {
    cin>>N>>M;
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    check[1] = 1;
    bfs();

    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}