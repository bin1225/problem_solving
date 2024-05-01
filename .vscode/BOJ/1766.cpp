#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int N, M;
int countLink[32023];
vector<int> G[32023];
vector<int> answer;
priority_queue<int, vector<int>, greater<int>> PQ;

void Solve() {
    cin>>N>>M;
    int a, b;

    for(int i=0; i<M; i++){
        cin>>a>>b;
        G[a].push_back(b);
        countLink[b]++;
    }

    for(int i=1; i<=N; i++) if(countLink[i] == 0) PQ.push(i);

    while(!PQ.empty()){
        int size = PQ.size();
        for(int i=0; i<size; i++){
            int n = PQ.top(); PQ.pop();
            answer.push_back(n);
            for(int j=0; j<G[n].size(); j++){
                if(--countLink[G[n][j]]==0) PQ.push(G[n][j]);
            }
        }
    }

    for(int ans: answer) cout<<ans<<" ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}