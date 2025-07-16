#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
        
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if(i+1 != arr[i]) {
            cout << i+1 << "\n";
            return 0;
        }
    }

    return 0;
}