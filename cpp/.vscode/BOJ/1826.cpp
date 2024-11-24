#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N,L,P;
priority_queue<int> gas;
vector<pair<int,int>> Stations;

void Solve() {
    cin>>N;

    int a, b, now=0, answer=0;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        Stations.push_back({a, b});
    }
    cin>>L>>P;
    Stations.push_back({L,0});
    sort(Stations.begin(), Stations.end());
    
    for(int i=0; i<Stations.size(); i++){
        while(P<Stations[i].first-now){
                if(gas.empty()){
                    cout<<-1; return;
                }
                P+=gas.top(); gas.pop();
                answer++;
        }
        P-=(Stations[i].first-now);
        now = Stations[i].first;
        gas.push(Stations[i].second);
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