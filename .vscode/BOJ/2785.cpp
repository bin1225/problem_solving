#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define ll long long
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> Chains;

void Solve() {
    cin>>N;
    int c, now, tobe;
    for(int i=0; i<N; i++){
        cin>>c; Chains.push(c);
    }    

    now = 0; tobe = Chains.size()-1;

    while(now<tobe){
        if(tobe-now>Chains.top()){
            now+=Chains.top(); tobe--;
            Chains.pop();
        }
        else {
            break; 
        }
    }

    cout<<tobe;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}