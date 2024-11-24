#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define endl "\n"

using namespace std;

int N;
long long answer[3];
vector<long long> V;

void Solve() {
    cin>>N;
    int n;
    long long result = LLONG_MAX;
    for(int i=0; i<N; i++) {
        cin>>n;
        V.push_back(n);
    }

    sort(V.begin(), V.end());

    for(int i=0; i<N-2; i++){
        int s = i+1, e = N-1;
        long long target = - V[i];
        
        while(s<e){
            long long sum = V[s] + V[e];

            if(result > abs(sum-target)){
                result = abs(sum-target);
                answer[0] = V[i]; answer[1] = V[s]; answer[2] = V[e];
            }
            
            if(sum<target) s++;
            else if(sum>target) e--;
            else break;
        }

        
    }

    for(int i=0; i<3; i++) cout<<answer[i]<<" ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}