#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<tuple<int,int,int>> schedule;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        schedule.push_back({a, b, i});
    }
    sort(schedule.begin(), schedule.end());
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(!pq.empty() && pq.top().first < get<0>(schedule[i])) {
            auto t = pq.top();
            pq.pop();
            ans[get<2>(schedule[i])] = t.second;
            pq.push({get<1>(schedule[i]), t.second});
        }
        else {
            count++;
            ans[get<2>(schedule[i])] = count;
            pq.push({get<1>(schedule[i]), count});
        }
    }

    cout << count<<"\n";
    for(int r: ans) {
        cout << r << " ";
    }
    return 0;
}
