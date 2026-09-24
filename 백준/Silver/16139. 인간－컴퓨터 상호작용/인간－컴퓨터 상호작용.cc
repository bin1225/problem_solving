#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;


int pf[202020][26];

void Solve() {
    
//    memset(pf, 0, sizeof(pf));
//    vector<vector<int>> pf(202020, vector<int>(26,0));

    string s; cin>>s;
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<26; j++) {
            if(j==s[i] - 'a') pf[i][j]++;
            if(i-1>=0) pf[i][j] += pf[i-1][j];
        }
    }

    int q; cin>>q;
    char a;
    int l,r;
    while(q-->0) {
        cin>>a>>l>>r;
        int left = (l-1>=0) ? pf[l-1][a-'a']:0;
        int right = pf[r][a-'a'];
        cout<<right - left<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}