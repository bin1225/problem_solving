#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl "\n"
#define INF 987654321
using namespace std;

int N;
int W[17][17];
int dist[16][1<<16];

int dfs(int now, int bitmask){
   if(bitmask == (1<<N)-1){
    if(W[now][0]>0){
        return W[now][0];
//        dist[0][bitmask] = min(dist[0][bitmask],dist[now][bitmask]+W[now][0]);
    }
    return INF;
   }

    if(dist[now][bitmask]!=-1) return dist[now][bitmask];
    dist[now][bitmask] = INF;
   for(int i=0; i<N; i++){
    if((W[now][i]<=0||bitmask & (1<<i))) continue;
    //if(dist[i][bitmask|(1<<i)] <= dist[now][bitmask] + W[now][i]) continue;
    
    dist[now][bitmask] = min(dist[now][bitmask] , W[now][i] + dfs(i,(bitmask|(1<<i))));
   
   }

   return dist[now][bitmask];
}


void Solve() {
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>W[i][j];
        }
    }

    fill(&dist[0][0], &dist[0][0] + 16 * (1<<16), -1);
    
    cout<<dfs(0,1);
    
    //cout<<dist[0][(1<<N)-1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}