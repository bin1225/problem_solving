#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, ans = 0;
    cin >> n >> x;

    vector<int> V;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }

    sort(V.begin(), V.end());
    int i, j;
    i = 0;
    j = V.size() - 1;
    while(i<=j) {
        if(V[i] + V[j] <= x) {
            i++;
            j--;
        }
        else {
            j--;
        }
        ans++;
    }

    cout << ans;
    return 0;
}