#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    ll l, r, m, time;
    l = 0;
    time = r = LLONG_MAX;
    while(l<r) {
        m = l + (r - l) / 2;

        ll count=0;
        for (int i = 0; i < n; i++) {
            count += m / machines[i];
            if(count>=t)
                break;
        }

        if(count>=t) {
            r = m;
            time = min(time, m);
        }
        else
            l = m + 1;
    }
    cout << time;

    return 0;
}