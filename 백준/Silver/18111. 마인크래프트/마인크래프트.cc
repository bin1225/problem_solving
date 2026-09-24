#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {

    int N, M, B;
    cin >> N >> M >> B;

    int arr[N][M];
    for (int i = 0; i<N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    pair<int, int> answer = {INT_MAX, 0};
    for (int h = 0; h <= 256; h++) {
        int blockCnt = B;
        int time = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(arr[i][j] > h) {
                    blockCnt += arr[i][j] - h;
                    time += 2 * (arr[i][j] - h);
                }
                else if(arr[i][j] < h) {
                    blockCnt -= (h - arr[i][j]);
                    time += h - arr[i][j];
                }
            }
        }
        if(blockCnt < 0)
            continue;
        if(answer.first >= time) {
            answer = {time, h};
        }
    }

    cout << answer.first << " " << answer.second;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}