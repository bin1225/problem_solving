#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

#define endl "\n"
#define pp pair<int,pair<int,int>>

using namespace std;

int N, M;
vector<vector<int>> V;

void Solve() {
    cin>>N>>M;
    int input;
    for(int i=0; i<N; i++)
    {
        vector<int> v;
        for(int j=0; j<M; j++){
            cin>>input;
            v.push_back(input);
        }
        sort(v.begin(), v.end());
        V.push_back(v);
    }
    
    priority_queue<pp, vector<pp>, greater<pp>> PQ;

    int maxVal = 0, answer = INT_MAX;
    for(int i=0; i<N; i++){
        maxVal = max(maxVal, V[i][0]);
        PQ.push({V[i][0],{i,0}});
    }

    pp info;
    while(!PQ.empty()){
        info = PQ.top(); PQ.pop();
        answer = min(answer, maxVal - info.first);

        int i = info.second.first; int j = info.second.second;
        if(j==M-1) break;
        maxVal = max(maxVal, V[i][j+1]);
        PQ.push({V[i][j+1], {i, j+1}});
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