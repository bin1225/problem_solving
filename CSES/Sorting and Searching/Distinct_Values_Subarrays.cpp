#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<int> s;
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while(j<i && s.count(nums[i]) > 0) {
            s.erase(nums[j]);
            j++;
        }
        s.insert(nums[i]);
        ans += s.size();
    }
        cout << ans;
    return 0;
}