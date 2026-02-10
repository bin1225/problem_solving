#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N;
    cin >> N;
    int arr[4][4040];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }

    vector<long long> v1, v2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v1.push_back(arr[0][i] + arr[1][j]);    
            v2.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(v2.begin(), v2.end());

    long long answer = 0;
    for (int i = 0; i < v1.size(); i++) {
        auto s = lower_bound(v2.begin(), v2.end(), -v1[i]);

        if(s == v2.end())
            continue;
        
        auto e = upper_bound(v2.begin(), v2.end(), -v1[i]);
        answer += e - s;
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