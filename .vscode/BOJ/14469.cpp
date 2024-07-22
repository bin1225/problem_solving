#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
vector<pair<int,int>> Cows;

void Solve() {
    cin>>N;

    int at, ct, time=0;
    for(int i=0; i<N; i++){
        cin>>at>>ct;
        Cows.push_back({at, ct});
    }

    sort(Cows.begin(), Cows.end());

    for(int i=0; i<Cows.size(); i++){
        if(Cows[i].first>time) time=Cows[i].first;
        time+=Cows[i].second;
    }

    cout<<time;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}