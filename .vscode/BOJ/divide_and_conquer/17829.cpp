#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int divideConquer(vector<vector<int>> A, int n){
    if(A.size()==1) return A[0][0];
    vector<vector<int>> v(n/2);

    for(int i=0; i<n/2; i++){
        int y=i*2;
        for(int j=0; j<n/2; j++){
            int x =j*2;
            vector<int> vv; 
            vv.push_back(A[y][x+1]); 
            vv.push_back(A[y+1][x]);
            vv.push_back(A[y+1][x+1]);
            vv.push_back(A[y][x]);
            sort(vv.begin(), vv.end());
            v[i].push_back(vv[2]);
        }
    }
    return divideConquer(v, n/2);
}

void Solve() {
    int N; cin>>N;
    int a;
    vector<vector<int>> V(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a;
            V[i].push_back(a);
        }
    }

    cout<<divideConquer(V,N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}