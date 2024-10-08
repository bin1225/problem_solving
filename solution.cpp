#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int C[101010];

void Solve() {
    int N; cin>>N;
    int a,b;
    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        C[a]++; C[b]++;
    }

    int q; cin>>q;
    int t,k;
    for(int i=0; i<q; i++){
        cin>>t>>k;
        if(t==1){
            if(C[k]>=2) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else cout<<"yes"<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}