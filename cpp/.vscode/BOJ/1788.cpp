#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

long long N, a, b, sum;

void Solve() {
    cin>>N;
     if(N<0) {
        a=0, b=1, sum=1;
        for(int i=-2; i>=N; i--){
        sum = (a-b)%1000000000;
        a = b;
        b = sum;
        }
        
    }
    else if(N>0){
        a=0, b=1, sum=1;
        for(int i=2; i<=N; i++){
        sum = (a+b)%1000000000;
        a = b;
        b = sum;
        }

    }

    if(sum==0) cout<<0<<endl;
    else if(sum>0) cout<<1<<endl;
    else cout<<-1<<endl;

    cout<<abs(sum);

    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}