#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N,L;
vector<pair<int,int>> V;

void Solve() {
    cin>>N>>L;

    int a,b;
    for(int i=0; i<N; i++){
        cin>>a>>b;
        V.push_back({a,b});
    }
    sort(V.begin(), V.end());
    
    int now = 0, ans = 0;
    for(int i=0; i<N; i++){
        if(V[i].first>now) now = V[i].first;

        while(now<V[i].second){
            now+=L;
            ans++;
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