#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    deque<int> deq;
    for (int i = 1; i <= n; i++) {
        deq.push_back(i);
    }

    vector<int> ans;
    while(!deq.empty()) {
        deq.push_back(deq.front());
        deq.pop_front();
        ans.push_back(deq.front());
        deq.pop_front();
    }

    for(int a: ans) {
        cout << a << " ";
    }
    return 0;
}