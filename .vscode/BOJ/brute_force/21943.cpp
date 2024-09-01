#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,P,Q;
vector<int> V;
vector<char> OP;

int cal(vector<int> v){
    vector<int> vv;
    int max_result=0;
    do{
        vv.clear();
        int tmp = V[0];
        for(int i=0; i<OP.size(); i++){
            if(OP[i]=='+') tmp+=V[i+1];
            else {
                vv.push_back(tmp);
                tmp=V[i+1];
            }
        }
        if(tmp!=0) vv.push_back(tmp);
        
        int result = vv[0];
        for(int i=1; i<vv.size(); i++){
            result*=vv[i];
        }
        max_result = max(max_result, result);
    }while(next_permutation(OP.begin(), OP.end()));

    return max_result;
}

void Solve() {
    cin>>N;
    int n;
    for(int i=0; i<N; i++){
        cin>>n; V.push_back(n);
    }
    cin>>P>>Q;
    for(int i=0; i<P; i++) OP.push_back('+');
    for(int i=0; i<Q; i++) OP.push_back('*');
    sort(V.begin(), V.end());
    sort(OP.begin(), OP.end());

    int ans=0;
    do{
        int result=cal(V);
        ans = max(ans, result);
    } while(next_permutation(V.begin(), V.end()));

    cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}