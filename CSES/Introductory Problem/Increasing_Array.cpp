#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll   a, b;
    cin >> a;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> b;
        if(a > b) {
            ans += (a - b);
            b = a;
        }
        a = b;
    }
    cout << ans;
    return 0;
}