#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define ll long long
using namespace std;

int T, N;

void Solve() {
    cin>>N;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    ll num, a, b, sum = 0;

    for(int i=0; i<N; i++){
        cin>>num;
        PQ.push(num);
    }

    while(PQ.size()>=2){
        a = PQ.top(); PQ.pop();
        b= PQ.top(); PQ.pop();

        sum+=a+b;
        PQ.push(a+b);
    }

    cout<<sum<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T-->0){
        Solve();
    }
    return 0;
}