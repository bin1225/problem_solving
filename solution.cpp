#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl "\n"

using namespace std;

long long N, M;

void Solve() {
    cin>>N>>M;

    long long find, answer = INT_MAX;
    long long arr[N];

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    sort(arr, arr+N);

    for(int i=0; i<N-1; i++){
        find = arr[i] + M;

        int idx = lower_bound(arr+i+1, arr+N, find) - arr;
        if(arr[idx] - arr[i] >= M)answer = min(answer, arr[idx] - arr[i]);
    }

    cout<< answer;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}