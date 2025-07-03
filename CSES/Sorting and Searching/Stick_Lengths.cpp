#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, mn, mx;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int mid = v[(v.size()-1) / 2];
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += abs(mid - v[i]);
    }

    cout << ans;
    return 0;
}