#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int T; cin>>T;
    int n; cin>>n;
    int A[n+1]; A[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>A[i];
        A[i] += A[i-1];
    }

    int m; cin>>m; 
    int B[m+1]; B[0] = 0;
    for(int i=1; i<=m ;i++) {
        cin>>B[i];
        B[i] += B[i-1];
    }

    vector<int> Va;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int sum = A[j] - A[i];
            Va.push_back(sum);
        }
    }

    vector<int> Vb;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<=m; j++) {
            int sum = B[j] - B[i];
            Vb.push_back(sum);
        }
    }

    sort(Vb.begin(), Vb.end());
    ll answer = 0;
    for(int i=0; i<Va.size(); i++) {
        int target = T - Va[i];
        auto s = lower_bound(Vb.begin(), Vb.end(), target);
        auto e = upper_bound(Vb.begin(), Vb.end(), target);
        int count = e - s;
        if(e!=Va.end()) answer +=count;
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