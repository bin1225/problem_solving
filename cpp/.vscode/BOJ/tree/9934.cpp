#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int K, idx;
int T[1111];
vector<int> V;

void travle(int n){
    if(T[n]==0&&n*2<=pow(2,K)-1) travle(n*2);
    T[n] = V[idx++];
    if(n*2+1<=pow(2,K)-1) travle(n*2+1);
}
void Solve() {
    cin>>K;
    int a;
    for(int i=0; i<pow(2,K); i++){
        cin>>a; V.push_back(a);
    }

    travle(1);
    
    queue<int> Q; int n;
    Q.push(1);
    while(!Q.empty()){
        int size = Q.size();
        for(int i=0; i<size; i++){
            n = Q.front(); Q.pop();
            cout<<T[n]<<" ";
            if(n*2+1<=pow(2,K)-1) {Q.push(n*2); Q.push(n*2+1);}
        }
        cout<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}