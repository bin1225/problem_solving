#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a, ans;

vector<int> V_m;
vector<int> V_p;


void Solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > 1) V_p.push_back(a);
        else if (a == 1) ans += 1;
        else V_m.push_back(a);
    }
    sort(V_p.begin(), V_p.end(), greater<>());
    sort(V_m.begin(), V_m.end());

    
    for (int i =0; i < V_m.size(); i++) {
        if (i != V_m.size() - 1) {
            ans += V_m[i] * V_m[i + 1]; i++;
        }
        else {
            ans += V_m[i];
        }
    }

    for (int i = 0; i < V_p.size(); i++) {
        if (i != V_p.size() - 1) {
            ans += V_p[i] * V_p[i + 1]; i++;
        }
        else {
            ans += V_p[i];
        }
    }
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}
