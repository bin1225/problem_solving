#include <iostream>
#include <string>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N;
    cin >> N;

    int a;
    int count[10101];
    fill(count, count + 10101, 0);
    for (int i = 0; i < N; i++) {
        cin >> a;
        count[a]++;
    }

    for (int i = 0; i <= 10000; i++) {
        if(count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                cout << i << endl;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}