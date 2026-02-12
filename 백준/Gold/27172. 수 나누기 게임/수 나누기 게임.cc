#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

bool numbers[1010101];
int scores[1010101];
void Solve() {
    memset(numbers, false, sizeof(numbers));
    memset(scores, 0, sizeof(scores));

    vector<int> v;
    int N, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        numbers[a] = true;
        v.push_back(a);
    }

    for (int i = 0; i <v.size(); i++) {
        int tmp = 2;
        while(v[i] * tmp <= 1000000) {
            if(numbers[v[i]*tmp]) {
                scores[v[i]]++;
                scores[v[i] * tmp]--;
            }
            tmp++;
        }
    }

    vector<int> answer; 
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(scores[v[i]]);
    }

    for(auto a: answer)
        cout << a << " ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}