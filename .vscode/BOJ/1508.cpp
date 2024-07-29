#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

#define endl "\n"

using namespace std;

int N,M,K;
vector<int> V;
vector<int> answer;
bool check(int dist){

    int cnt = 0, tmp, idx = 0;
    while(cnt<M){
        tmp=0;
        while(idx<V.size()&&tmp<dist){
            tmp+=V[idx]; idx++;
        }
        if(tmp>=dist) cnt++;
        else break;
    }

    return cnt>=M-1;
}
void Solve() {
    cin>>N>>M>>K;
    int befo, now;
    cin>>befo;
    for(int i=1; i<K; i++){
        cin>>now;
        V.push_back(now-befo);
        befo = now;
    }
    int l,r,m,d=0;
    l=0; r=N; m =N;
    while(l<r){
        if(check(m)) { d = max(d,m); l=m+1;}
        else r=m;
        m = (l+r)/2;
    }
    m=d;
    answer.push_back(1);
    int tmp=0; M--;
    for(int i=0; i<V.size(); i++){
        tmp+=V[i];
        
        if(tmp>=m&&M>0){ tmp=0; answer.push_back(1); M--;}
        else {
            answer.push_back(0);
        }
    }

    for(int n: answer) cout<<n;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}