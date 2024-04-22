#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX_LOC 1000000
using namespace std;

int N, K;
int st[1010101];
int ed[1010101];
int arr[1010101];

void Solve() {
    cin>>N>>K;
    int a, b, tmp, nowLen, s, e;

    for(int i=0; i<N; i++){
        cin>>a>>b;
        st[a]++; ed[b]++;
    }

    tmp = 0;
    for(int i=0; i<=1000000; i++){
        tmp+=st[i]; tmp -= ed[i];
        arr[i] = tmp;
    }

    nowLen = s = e = 0;
    for(s=0; s<MAX_LOC; s++){
        while(nowLen < K && e < MAX_LOC){
            nowLen+=arr[e]; e++;
        }
        if(nowLen==K) break;
        nowLen-=arr[s];
    }
    if(nowLen!= K) cout<<"0 0";
    else cout<<s<<" "<<e;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}