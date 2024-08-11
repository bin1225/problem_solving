#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n"

using namespace std;

int N;
pair<int,long long> A[11];

bool compare(pair<int,long long> a, pair<int,long long> b){
    if(a.first == b.first) return a.second >= b.second;
    else return a.first >= b.first;
}
void Solve() {
    cin>>N;
    string s;

    for(int i=0; i<N; i++){
        cin>>s;
        A[s[0]-'A'].first = 1;
        for(int j=0; j<s.size(); j++){
            A[s[j]-'A'].second+=pow(10,s.size()-j-1);
        }
    }
    
    long long sum=0;
    sort(A, A+10, compare);
    for(int i=0; i<9; i++) A[i].first = 1;
    sort(A, A+10, compare);

    for(int i=0; i<10; i++){
        sum+= A[i].second*(9-i);
    }

    cout<<sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}
