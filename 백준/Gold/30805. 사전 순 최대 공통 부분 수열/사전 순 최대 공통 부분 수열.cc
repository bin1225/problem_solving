#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    int N, M;
    cin >> N;

    int arrA[N];
    for (int i = 0; i < N; i++) {
        cin >> arrA[i];
    }

    cin >> M;
    int arrB[M];
    for (int i = 0; i < M; i++) {
        cin >> arrB[i];
    }

    vector<pair<int, int>> answer;
    for (int i = 0; i < N; i++) {
        int num = arrA[i];
        int idx = 0;
        pair<int, int> base = {0, -1};
        while(idx<answer.size() && answer[idx].first >= num) {
            base = answer[idx];
            idx++;
        }

        auto it = find(arrB + base.second +1, arrB + M, num);
        if(it!= arrB + M) {
            while(!answer.empty() && answer.back().first < num)
                answer.pop_back();
            answer.push_back({num, it - arrB});
        }
    }

    cout << answer.size() << endl;
    if(answer.size() != 0) {
        for(auto a: answer) {
            cout << a.first << " ";
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