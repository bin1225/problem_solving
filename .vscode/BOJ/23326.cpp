#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl "\n"

using namespace std;

int N, Q;
set<int> S;

void Solve() {
    cin>>N>>Q;

    int n, idx, x, now=1;
    
    for(int i=1; i<=N; i++){
        cin>>n;
        if(n==1) S.insert(i);
    }

    for(int i=0; i<Q; i++){
        cin>>n;
        if(n==1){
            cin>>idx;
            if(!S.erase(idx)) S.insert(idx);
        }
        else if(n==2){
            cin>>x;
            now+=(x%N); now%=N; if(now==0) now=N;
        }
        else{
            if(S.empty()) {
                cout<<-1<<endl;
                continue;
            }

            auto to = S.lower_bound(now);
            if(to == S.end()) cout<<N-now + *S.begin()<<endl;
            else cout<<*to - now<<endl;
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