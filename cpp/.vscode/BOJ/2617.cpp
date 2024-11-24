#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl "\n"

using namespace std;

int N, M;
bool visited[101];
vector<int> G1[101]; //무거운 구슬 -> 가벼운 구슬
vector<int> G2[101]; //가벼운 구슬 -> 무거운 구슬


int dfs1(int n){
    int next, cnt=0;

    for(int i=0; i<G1[n].size(); i++){
        next = G1[n][i];
        if(visited[next]) continue;
        visited[next] = true;

        cnt+=(dfs1(next)+1);
    }
    
    return cnt;
}

int dfs2(int n){
    int next, cnt=0;
    
    for(int i=0; i<G2[n].size(); i++){
        next = G2[n][i];
        if(visited[next]) continue;
        visited[next] = true;

        cnt+=(dfs2(next)+1);
    }

    return cnt;
}

void Solve() {
    cin>>N>>M;

    int a, b, cntH, cntL, answer=0;

    for(int i=0; i<M; i++){
        cin>>a>>b;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        fill(visited, visited+N+1, false);
        visited[i] = true;
        cntL = dfs1(i);
        
        
        fill(visited, visited+N+1, false);
        visited[i] = true;
        cntH = dfs2(i);
        //cout<<"i:"<<i<<"  "<<cntH<<" "<<cntL<<endl;
        if(cntH >N/2 || cntL > N/2) answer++;
    }

    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}