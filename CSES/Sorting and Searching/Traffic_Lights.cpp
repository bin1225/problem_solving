#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    multiset<int> distance = {x};
    set<int> traffic = {0,x};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto r = traffic.upper_bound(p);
        auto l = prev(r);

        distance.erase(distance.find(*r - *l));

        distance.insert(*r - p);
        distance.insert(p - *l);

        traffic.insert(p);
        cout << *distance.rbegin()<<" ";
    }
    return 0;
}