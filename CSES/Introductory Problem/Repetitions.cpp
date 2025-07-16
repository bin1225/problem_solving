#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int len = 1, ans = 1;
    for (int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]){
            len++;
            ans = max(ans, len);
        }
        else {
            len = 1;
        }
    }
    cout << ans << "\n";
        return 0;
}