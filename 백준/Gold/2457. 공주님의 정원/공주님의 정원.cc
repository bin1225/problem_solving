#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    int N;
    cin >> N;

    vector<pair<int, int>> flowers;

    int ma, da, mb, db;
    for (int i = 0; i < N; i++) {
        cin >> ma >> da >> mb >> db;
        if(ma * 100 + da > 1130||mb * 100 + db < 301)
            continue;
        flowers.push_back({ma * 100 + da, mb * 100 + db});
    }

    sort(flowers.begin(), flowers.end());

    int start = 301;
    int answer = 0;
    int idx = 0;
    while(idx<N) {
        if(start > 1130)
            break;
        if(start < flowers[idx].first) {
            cout << 0;
            return;
        }

        int end = flowers[idx].second;
        while(idx<N && flowers[idx].first <= start) {
            end = max(end, flowers[idx].second);
            idx++;
        }

        start = end;
        answer++;
    }

    if(start <= 1130)
        cout << 0;
    else cout << answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}