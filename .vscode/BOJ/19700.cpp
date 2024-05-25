#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define endl "\n"

using namespace std;

int N;
priority_queue<pair<int,int>> PQ;
multiset<int> Teams;

void Solve() {
    cin>>N;
    int h, k;
    for(int i=0; i<N; i++){
        cin>>h>>k;
        PQ.push({h,k});
    }

    pair<int,int> pp;
    while(!PQ.empty()){
        pp = PQ.top(); PQ.pop();
        auto iter = Teams.lower_bound(pp.second);
        if(iter == Teams.begin()){
            Teams.insert(1);
        }
        else if(*prev(iter)<pp.second){
            int count = *prev(iter);
            Teams.erase(prev(iter));
            Teams.insert(count+1);
        }
        
    }
    cout<<Teams.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}