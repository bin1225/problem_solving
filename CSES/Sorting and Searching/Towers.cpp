#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cube;
    vector<int> towers;

    for (int i = 0; i < n; i++) {
        cin >> cube;
        if(towers.empty()||towers.back()<=cube)
            towers.push_back(cube);
        else {
            auto it = upper_bound(towers.begin(), towers.end(), cube);
            *it = cube;
        }
    }
    cout << towers.size();
    return 0;
}