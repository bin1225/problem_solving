#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> app;
    vector<int> apt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        app.push_back(a);
    }
 
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        apt.push_back(a);
    }
    sort(app.begin(), app.end());
    sort(apt.begin(), apt.end());

    int i, j, ans;
    i = j = ans = 0;
    while(i<n && j<m) {
        if(app[i] < apt[j] - k)
            i++;
        else if (app[i] > apt[j] +k)
            j++;
        else {
            ans++;
            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}