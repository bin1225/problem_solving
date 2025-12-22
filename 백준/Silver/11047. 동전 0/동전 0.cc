#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N, K;
    cin >> N >> K;

    int coin;
    vector<int> coins;

    for (int i = 0; i < N; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    sort(coins.begin(), coins.end(), greater<>());
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if(K > 0) {
            answer += (K / coins[i]);
            K %= coins[i];
        }
    }
    cout << answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}