#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int A[10];
void Solve() {
    
    int sum =0;
    for(int i=0; i<9; i++){
        cin>>A[i];
        sum+=A[i];
    }

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum-(A[i]+A[j])==100){
                vector<int> V;
                for(int k=0; k<9; k++){
                    if(k!=i&&k!=j) V.push_back(A[k]);
                }
                sort(V.begin(), V.end());
                for(auto n: V) cout<<n<<endl;
                return;
            }
        }
    }

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}