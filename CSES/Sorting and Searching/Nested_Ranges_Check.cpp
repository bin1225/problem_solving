#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<tuple<int, int, int>> range;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        range.push_back({a, b, i});
    }

    sort(range.begin(), range.end(), [](auto a, auto b) {
        if(get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });
    vector<int> contains(n), contained(n);
    int end_max = 0;
    for (int i = 0; i<n; i++) {
        auto [a, b, c] = range[i];
        if(end_max >= b) {
            contained[c] = 1;
        }
        else 
            end_max = max(b, end_max);
    }

    sort(range.begin(), range.end(), [](auto a, auto b) {
        if(get<0>(a) != get<0>(b))
            return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    int end_min = INT_MAX;
    for (int i = 0; i < n; i++) {
        auto [a, b, c] = range[i];
        if(end_min <= b) {
            contains[c] = 1;
        }
        else 
            end_min = min(b, end_min);
    }

    for (int c : contains){
            cout << c << " ";
    }
    cout << "\n";
    for(int c: contained) {
        cout << c << " ";
    }
    return 0;
}