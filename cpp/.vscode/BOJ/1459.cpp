#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

long long X,Y,W,S;

void Solve() {
    cin>>X>>Y>>W>>S;
    long long  answer;
    if(W*2>S){
        long long minN = min(X,Y); 
        long long maxN = max(X,Y);
        answer = minN*S;
        if(W<S) answer+=(maxN-minN)*W;
        else {
            answer+=(maxN-minN)*S;
            if((maxN-minN)%2==1) answer+=(W-S); 
        }
    }
    else {
        answer = (X+Y)*W;
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