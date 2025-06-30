#include<bits/stdc++.h>

#define ll long long

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second != b.second)
        return a.second < b.second;
    else 
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;

    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        V.push_back({a, b});
    }

    sort(V.begin(), V.end(), comp);

    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if(now <= V[i].first) {
            cnt++;
            now = V[i].second;
        } 
    }

    cout << cnt;
    return 0;
}