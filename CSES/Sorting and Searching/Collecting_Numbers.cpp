#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans;
    cin >> n;
    ans = 1;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}