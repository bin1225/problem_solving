#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#define endl "\n"

using namespace std;

int N, K, M;    
int dist[101010];
bool visitedTube[1010];
map<int, vector<int>> G;
map<int, vector<int>> Tube; 
void Solve() {
    cin>>N>>K>>M;
    
    int n, now, next, a, b, tubeNum;
    vector<int> V;
    queue<int> Q;
    fill(dist,dist+N+1, -1);
    fill(visitedTube, visitedTube+M+1, false);
    
    for(int i=0; i<M; i++){
        V.clear();
        for(int j=0; j<K; j++){
            cin>>n;
            G[n].push_back(i);
            V.push_back(n);
        }
        Tube[i] = V;
    }


    Q.push(1); dist[1] = 1;
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        if(now==N) break;

        for(int i=0; i<G[now].size(); i++){
            
            tubeNum = G[now][i];
            if(visitedTube[tubeNum]) continue;
            visitedTube[tubeNum] = true;
            
            for(int j=0; j<Tube[tubeNum].size(); j++){
                next = Tube[tubeNum][j];
                if(dist[next]>0) continue;
                dist[next] = dist[now]+1;
                Q.push(next);
            }
        }
    }
    
    cout<<dist[N];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}