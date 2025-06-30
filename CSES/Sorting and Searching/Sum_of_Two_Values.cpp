#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back({a,i});
    }

    sort(v.begin(), v.end());

    int i, j;
    i = 0;
    j = v.size() - 1;
    while(i<j) {
        ll sum = v[i].first + v[j].first;
        if(sum == x)
            break;
        else if(sum < x)
            i++;
        else
            j--;
    }
    if(i<j) cout << v[i].second+1 << " " << v[j].second+1;
    else
        cout << "IMPOSSIBLE";
    return 0;
}