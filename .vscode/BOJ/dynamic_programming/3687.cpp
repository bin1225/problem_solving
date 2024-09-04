#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

string NUMS[] = {"X","X","1","7","4","2","0","8"};
string minDP[101] = {"X","X","1","7","4","2","6","8","10"};
string maxDP[101];

string get_max(int n){
    string res="";
    if(n%2!=0 && n>=3) {res+="7"; n-=3;}
    while(n>0){
        res+="1"; n-=2;
    }
    return res;
}

string get_min(string a, string b){

    if(a.size()>b.size()) return b;
    else if(b.size()>a.size()) return a;
    else{
        for(int i=0; i<a.size(); i++){
            if(a[i]>b[i]) return b;
            else if(a[i]<b[i]) return a;
        }
        return a;
    }
}

void Solve() {
    for(int i=2; i<=100; i++) maxDP[i] = get_max(i);
    
    for (int i = 9; i <= 100; i++) {
        minDP[i] = minDP[i-2] + NUMS[2]; 
        for (int j = 3; j < 8; j++) {
            minDP[i] = get_min(minDP[i], minDP[i-j] + NUMS[j]);
        }
    }

    int T; cin>>T;
    while(T-->0){
        int N; cin>>N;
        cout<<minDP[N]<<" "<<maxDP[N]<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}