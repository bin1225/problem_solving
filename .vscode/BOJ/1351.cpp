#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define endl "\n"

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> H;

long long dfs(long long n){
    if(H.count(n)) return H[n];
    else {
        H[n] = dfs(n/P) + dfs(n/Q);
        return H[n];
    } 
}
void Solve() {
    cin>>N>>P>>Q;
    H[0] = 1;

    cout<<dfs(N);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}