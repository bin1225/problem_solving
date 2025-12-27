#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> V;
void Solve() 
{
    cin >> N;
    int a, b, ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        V.push_back({ a,b });
    }

    sort(V.begin(), V.end());

    int start = V[0].first, end = V[0].second;
    for (int i = 1; i < V.size(); i++) {
        if (V[i].first <= end) {
            end = max(end, V[i].second);
        }
        else {
            ans += end - start;
            start = V[i].first; end = V[i].second;
        }
    }

    ans += end - start;
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}


