#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;
int N;
vector<pair<ll,ll>> V;

void Solve() {
    cin>>N;
    ll x,a,left,right;
    right=0; left=0;
    for(int i=0; i<N; i++){
        cin>>x>>a;
        V.push_back({x,a}); right+=a;
    }

    sort(V.begin(), V.end());

    ll ans;
    for(int i=0; i<V.size(); i++){
        right-=V[i].second;
        left+=V[i].second;
        if(right<=left){
            ans = V[i].first; break;
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