#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

string T;
int N;
vector<pair<int,string>> Books;

bool chk(int cnt[]){
    for(int i=0; i<T.size(); i++){
        if(--cnt[T[i]-'A']<0) return false; 
    }
    return true;
}

void Solve() {
    cin>>T>>N;

    int c; string w;
    for(int i=0; i<N; i++){
        cin>>c>>w;
        Books.push_back({c,w});
    }

    int ans = INT_MAX;
    for(int i=0; i<pow(2,N); i++){
        int price=0;
        int cnt[30]; memset(cnt, 0, sizeof(cnt));
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                price+=Books[j].first;
                for(char c: Books[j].second){
                    cnt[c-'A']++;
                }
            }
        }
        if(chk(cnt)) ans = min(ans, price);
    }

    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}