#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl "\n"
#define ll long long
using namespace std;

int N;
vector<pair<ll,ll>> V;

void Solve() {
    cin>>N;
    ll x,a,sum=0,left,right,tmp,ans;
    for(int i=0; i<N; i++){
        cin>>x>>a;
        sum+=a;
        V.push_back({x,a});
    }

    sort(V.begin(), V.end());

    left=0; right=sum; tmp=LLONG_MAX;
    for(int i=0; i<V.size(); i++){
        right-=V[i].second;
        //cout<<"i: "<<i<<" l: "<<left<<"  r: "<<right<<endl;
        if(tmp>abs(right-left)) {tmp=abs(right-left); ans = V[i].first;}
        left+=V[i].second; 
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