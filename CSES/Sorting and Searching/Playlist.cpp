#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> song(n);
    for (int i = 0; i < n; i++) {
        cin >> song[i];
    }

    map<int,int> m;
    int left, right, ans;
    left = right = ans = 0;
    
    while(right < n) {
        if(m.count(song[right]) != 0) {
            left = max(left, m[song[right]] + 1);
        }
        m[song[right]] = right;
        ans = max(ans, right - left + 1);
        right++;
    }
    cout << ans;
    return 0;
}