#include<bits/stdc++.h>

#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count[n+1];
    memset(count, 0, sizeof(count));
    count[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=6; j++) {
            if(i-j >= 0) {
                count[i] += count[i - j];
                count[i] %= MOD;
            }
        }
    }

    cout << count[n];
    return 0;
}