#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define ll long long

using namespace std;

int N,M,L,K;
vector<pair<int,int>> Stars;

void Solve() {
    cin>>N>>M>>L>>K;
    int x,y;
    for(int i=0; i<K; i++){
        cin>>x>>y;
        Stars.push_back({x,y});
    }

    pair<int,int> a,b,c;
    int cnt,ans=101;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            a=Stars[i]; b=Stars[j];
            x=a.first; y=b.second;
            cnt = 0;
            for(int k=0; k<K; k++){
                c=Stars[k];
                if(c.first<x||c.first>x+L||c.second<y||c.second>y+L) cnt++;
            }
            ans = min(ans,cnt);
        }   
    }   
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}