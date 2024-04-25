#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N, C, M;


void Solve() {
    cin>>N>>C;
    cin>>M;
    vector<pair<int,int>> V[2020];
    int a,b,c;
    int nowLoc = 0, nowCount = 0, answer = 0, idx = 0;

    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        V[a].push_back({b,c});
    }

    for(int i=0; i<=N; i++){
        sort(V[i].begin(), V[i].end());
    }

    priority_queue<pair<int,int>> PQ;

    for(int i=0; i<=N; i++){

        //i번째에서 내리는 택배를 다 내린다.
        while(!PQ.empty() && PQ.top().first == -i){
            //cout<<i<<" "<<PQ.top().second<<endl;
            answer+=PQ.top().second; PQ.pop();
        }

        //i번째에서 보내는 택배를 일단 다 실는다.
        for(int j=0; j<V[i].size(); j++){
            PQ.push({-V[i][j].first, V[i][j].second});
        }

        //트럭 용량을 맞춘다.
        vector<pair<int,int>> V;
        nowCount = 0;
        while(!PQ.empty() && nowCount<C){
            pair<int,int> p = PQ.top(); PQ.pop();
            int count = min(C-nowCount, p.second);
            nowCount+=count;
            V.push_back({p.first, count});
        }

        while(!PQ.empty()) PQ.pop();
        for(int i=0; i<V.size(); i++) PQ.push(V[i]);

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