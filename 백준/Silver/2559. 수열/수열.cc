#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N, K;
    cin >> N >> K;

    vector<int> temp(N);
    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    vector<int> prefixSum(N, 0);
    prefixSum[0] = temp[0];

    for (int i = 1; i < N; i++) {
        prefixSum[i] += prefixSum[i - 1] + temp[i];
    }

    int answer = prefixSum[K-1];
    for (int i = K; i < N; i++) {
        answer = max(answer, prefixSum[i] - prefixSum[i - K]);
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