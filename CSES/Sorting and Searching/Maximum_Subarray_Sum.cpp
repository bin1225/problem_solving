#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    ll ans, sum;
    ans = sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum = max(a, sum+a);
        ans = max(ans, sum);
    }
    
    cout << ans;
    return 0;
}