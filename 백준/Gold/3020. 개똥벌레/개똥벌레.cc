#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N, H;
    cin>>N>>H;

    vector<int> V(H+1,0);
    int count = 0;
    for(int i=0; i<N; i++) {
        int a; cin>>a;
        if(i%2==0) {
            V[a]--; count++;
        }
        else V[H-a]++;
    }

    pair<int,int> answer = {N, 0};
    for(int i=1; i<=H; i++) {
        if(count < answer.first) {
            answer = {count, 1};
        }
        else if(count == answer.first) {
            answer = {answer.first, answer.second+1};
        }
        count+=V[i];
    }
    cout<<answer.first<<" "<<answer.second;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}