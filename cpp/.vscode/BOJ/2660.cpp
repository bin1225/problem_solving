#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define endl "\n"

using namespace std;

int N;
int dist[51];
unordered_map<int,vector<int>> G;

int bfs(int n){

    int maxDist = 0;
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()){
        int now = q.front(); q.pop();
        maxDist = max(maxDist, dist[now]);

        for(int i=0; i<G[now].size(); i++){
            int next = G[now][i];
            if(dist[next]>=0) continue;
            dist[next] = dist[now]+1;
            q.push(next); 
        }
    }

    return maxDist;
}

void Solve() {
    cin>>N;
    int a, b;
    int presidentScore = 50;
    vector<int> candidates;

    while(a!=-1 && b!=-1){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        fill(dist, dist+N+1, -1);
        int score = bfs(i);
        
        if(score<presidentScore){
            presidentScore = score;
            candidates.clear();
            candidates.push_back(i);
        }
        else if(score == presidentScore) candidates.push_back(i);
    }

    sort(candidates.begin(), candidates.end());

    cout<<presidentScore<<" "<<candidates.size()<<endl;
    for(int n: candidates) cout<<n<<" ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}