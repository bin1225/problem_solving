#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void Solve() {
    int N,M; cin>>N>>M;
    map<char,int> cnt;
    vector<string> V;
    string s="",ss;

    for(int j=0; j<N; j++){
        cin>>ss; V.push_back(ss);
    }

    int tmp,ans=0;
    char c;
    for(int i=0; i<M; i++){
        cnt['A']=0; cnt['C']=0; cnt['G']=0; cnt['T']=0;
        for(int j=0; j<N; j++){
            cnt[V[j][i]]++;
        }    
        c='A'; tmp = cnt['A'];
        if(tmp<cnt['C']){c='C'; tmp = cnt['C'];}
        if(tmp<cnt['G']){c='G'; tmp = cnt['G'];}
        if(tmp<cnt['T']){c='T'; tmp = cnt['T'];}
        s+=c;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(V[i][j]!=s[j]) ans++;
        }
    }
    cout<<s<<endl<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}