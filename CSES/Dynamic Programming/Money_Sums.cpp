#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int max_sum = 100000;
    vector<bool> possible(max_sum + 1, false);

    possible[0] = true;
    for(int coin: coins) {
        for (int i = max_sum; i>= 0; i--){
            if(possible[i])
                possible[i + coin] = true;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= max_sum; i++) {
        if(possible[i])
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(int a: ans) {
        cout << a << " ";
    }
    return 0;
}