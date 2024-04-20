#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, K;
int arr[1010101];

void Solve() {
    cin>>N>>K;
    int s, e, now, answer = 0;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    s = e = now = 0;

    while(e < N){
        if(arr[e]%2 ==0){   //짝수인 경우
            answer = max(answer, e-s+1);
        }
        else if(now<K){ //홀수지만 삭제 가능 횟수가 남아있는 경우
            now++; answer = max(answer, e-s+1);
        }
        else{ //홀수이고 삭제 가능 횟수가 없는 경우
            while(arr[s]%2==0) s++;
            s++;
        }
        e++;
    }

    cout<<answer - min(now,K);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}