#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> endTime;

    int s, e;
    vector<pair<int, int>> classes;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        classes.push_back({s, e});
    }

    sort(classes.begin(), classes.end());

    int answer = 0;
    for (int i = 0; i<classes.size(); i++) {
        if(endTime.empty() || endTime.top() > classes[i].first) {
            answer++;
        }
        else {
            endTime.pop();
        }
        
        endTime.push(classes[i].second);
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