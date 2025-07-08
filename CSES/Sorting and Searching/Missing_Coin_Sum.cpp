#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    ll now = 0;
    for (int i = 0; i < n; i++) {
        if(v[i]>now+1)
            break;
        else {
            now += v[i];
        }
    }
    cout << now+1;
    return 0;
}