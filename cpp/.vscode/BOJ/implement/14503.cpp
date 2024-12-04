#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

void claen(int r, int c, int d);
int Room[50][50];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int ans = 0; 

void clean(int r, int c, int d){
    if(Room[r][c]==0) {
        Room[r][c] = 2;
        ans++;
    }

    for(int i=0; i<4; i++){
        d = (d+3)%4;
        int nr = r+dr[d];
        int nc = c+dc[d];

        if(Room[nr][nc] == 0){
            clean(nr,nc,d);
            return;
        } 
    }

    int back = (d+2)%4;
    int br = r+dr[back];
    int bc = c+dc[back];

    if(Room[br][bc]!=1){
        clean(br,bc,d);
    }
}

void Solve() {
    int N,M,r,c,d; cin>>N>>M>>r>>c>>d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>Room[i][j];
        }
    }   
    clean(r,c,d);
    cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}