#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    string a, b;
    cin >> a >> b;

    if(a.size() !=b.size()) {
        cout << "Impossible" << endl;
        return;
    }

    int alphaCount[26];
    fill(alphaCount, alphaCount + 26, 0);

    for (int i = 0; i < a.size(); i++) {
        alphaCount[a[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); i++) {
        alphaCount[b[i] - 'a']--;
        if(alphaCount[b[i] - 'a'] < 0) {
            cout << "Impossible" << endl;
            return;
        }
    }

    cout << "Possible" << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N-->0) {
        Solve();
    }
    return 0;
}