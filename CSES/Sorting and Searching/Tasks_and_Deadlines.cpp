#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<ll,ll>> task;
    for (int i = 0; i < n; i++) {
        ll a, d;
        cin >> a >> d;
        task.push_back({a, d});
    }

    sort(task.begin(), task.end());

    ll ans = 0;
    ll now = 0;
    for (int i = 0; i<n; i++) {
        now += task[i].first;
        ans += task[i].second - now;
    }
    cout << ans;
    return 0;
}