#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a, ans = 1;
    cin >> N;
    vector<int> V;
    for (int i = 0; i < N; i++) {
        cin >> a;
        V.push_back(a);
    }

    sort(V.begin(), V.end());
    for(int i=1; i<N; i++) {
        if(V[i-1] != V[i])
            ans++;
    }

    cout << ans;
    return 0;
}