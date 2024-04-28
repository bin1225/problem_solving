#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, S;
long long arr[41];
bool check[41];
vector<long long> V1, V2;

void buildV(int n, int depth, int start, int end){
    if(depth>=end){
        long long sum = 0;
        for(int i=start; i<end; i++){
            if(check[i]) sum+=arr[i];
        }
        if(n==1) V1.push_back(sum);
        else if(n==2) V2.push_back(sum);
        return;
    }

    buildV(n, depth+1, start, end);
    check[depth] = true;
    buildV(n, depth+1, start, end);
    check[depth] = false;
}

void Solve() {
    cin>>N>>S;
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<N; i++) check[i] = false;

    buildV(1, 0, 0, N/2);
    buildV(2, N/2, N/2, N);

    sort(V2.begin(), V2.end());

    long long answer = 0;
    for(int i=0; i<V1.size(); i++){
        long long find = S - V1[i];

        int dIdx = lower_bound(V2.begin(), V2.end(), find) -V2.begin();
        
        if(find == V2[dIdx]){
            int uIdx = upper_bound(V2.begin(), V2.end(), find) - V2.begin();
            answer += uIdx - dIdx;
        }
    }
    if(S==0) answer--;
    cout<<answer;
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}