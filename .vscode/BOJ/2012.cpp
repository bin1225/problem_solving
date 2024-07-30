#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
vector<long long> V;

void Solve() {
    cin>>N;
    int a;
    for(int i=0; i<N; i++){
        cin>>a;
        V.push_back(a);
    }

    sort(V.begin(), V.end());

    long long answer=0;
    for(int i=0; i<V.size(); i++){
        answer+=abs(V[i]-(i+1));
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