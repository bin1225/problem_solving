#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> UQ;
priority_queue<int> DQ;

void Solve() {
    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        if(DQ.empty() || DQ.top()>=num) DQ.push(num);
        else UQ.push(num);
        
        while(DQ.size() < UQ.size()){
            if(UQ.empty()) break;
            DQ.push(UQ.top()); UQ.pop();
        }
        while(DQ.size()-1 > UQ.size()){
            UQ.push(DQ.top()); DQ.pop();
        }
        cout<<DQ.top()<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}