#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void run_left(int idx, int dir);
void run_right(int idx, int dir);

vector<string> V;

void rotate(string& s, int dir){
    if(dir == 1){
        char c = s.back();
        char bf;
        for(int i=s.size()-1; i>0; i--){
            s[i] = s[i-1];
        }
        s[0] = c;
    }
    else {
        char c = s.front();
        for(int i=0; i<s.size()-1; i++) s[i] = s[i+1];
        s.back() = c;    
    }
}

void run_left(int idx ,int dir){
    if(idx<0) return;
    if(V[idx][2] != V[idx+1][6]) {
        run_left(idx-1, -dir);
        rotate(V[idx], dir);
    }
}

void run_right(int idx, int dir){
    if(idx>3) return;
    if(V[idx][6] != V[idx-1][2]) {
        run_right(idx+1, -dir);
        rotate(V[idx], dir);
    }
}

void Solve() {  
    string s; 
    for(int i=0; i<4; i++){
        cin>>s;
        V.push_back(s);
    }

    int K,idx,dir;
    cin>>K; 
    while(K-->0){
        cin>>idx>>dir;
        idx--;
        run_right(idx+1, -dir);
        run_left(idx-1, -dir);
        rotate(V[idx],dir);
    }

    int ans = 0;
    for(int i=0; i<V.size(); i++){
        if(V[i][0] == '1') ans+=pow(2,i);
        
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