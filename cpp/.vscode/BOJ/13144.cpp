#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
int arr[101010];
int cnt[101010];

void Solve() {
    int s, e;
    long long answer = 0;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }

    s= e = 1;
    while(e<=N+1){
        if(cnt[arr[e]] == 0 && e != N+1){
            cnt[arr[e]]++;
        }
        else{
            answer+= (double)(e-s + 1)*(e-s)/2;
            while(cnt[arr[e]]!=0 && s<e) cnt[arr[s++]]--;
            cnt[arr[e]]++;
            if(e!=N+1) answer-= (double)(e-s + 1)*(e-s)/2;
        }
        e++;
    }

    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}