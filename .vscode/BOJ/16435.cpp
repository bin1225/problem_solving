#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, L;

void Solve() {
    cin>>N>>L;
    vector<int> H;
    int h;
    for(int i=0; i<N; i++){
        cin>>h; H.push_back(h);
    }

    sort(H.begin(), H.end());
    
    for(int i=0; i<N; i++){
        if(H[i]<=L) L++;
    }
    cout<<L;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}