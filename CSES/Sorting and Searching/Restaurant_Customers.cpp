#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> in;
    vector<int> out;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        in.push_back(a);
        out.push_back(b);
    }

    int count, max_count;
    count = max_count = 0;

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    int i, j;
    i = j = 0;
    while(i<n) {
        if(in[i] < out[j]) {
            count++;
            i++;
        }
        else {
            j++;
            count--;
        }
        max_count = max(count, max_count);
    }

    cout << max_count;

    return 0;
}