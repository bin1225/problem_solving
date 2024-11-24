#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int H,W,N; 
vector<pair<int,int>> V; 

bool chk(pair<int,int> a, pair<int,int> b){
    int w1,w2,h1,h2;
    w1=a.first; w2=b.first; h1=a.second; h2=b.second;
    if(w1+w2<=H && max(h1,h2)<=W) return true;
    else if(w1+w2<=W && max(h1,h2)<=H) return true;
    else if(h1+h2<=H&& max(w1,w2)<=W) return true;
    else if(h1+h2<=W&& max(w1,w2)<=H) return true;
    else if(w1+h2<=W&& max(h1,w2)<=H) return true;
    else if(w1+h2<=H&& max(h1,w2)<=W) return true;
    else if(h1+w2<=W&& max(w1,h2)<=H) return true;
    else if(h1+w2<=H&& max(w1,h2)<=W) return true;
    
    return false;
}

void Solve() {
    cin>>H>>W>>N;
    int r,c;
    for(int i=0; i<N; i++){
        cin>>r>>c;
        V.push_back({r,c});
    }

    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(chk(V[i],V[j])) ans = max(ans, V[i].first*V[i].second+V[j].first*V[j].second);
        }
    }

    cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}