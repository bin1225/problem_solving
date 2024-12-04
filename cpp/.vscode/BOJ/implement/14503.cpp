#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int Room[50][50];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M,r,c,d,ans; 

void clean_room(){
    if(Room[r][c]==0) {
        Room[r][c] = 2;
        ans++;
    }
}

bool check(){
    for(int i=0; i<4; i++){
        if(Room[r+dy[i]][c+dx[i]] == 0) return true;
    }
    return false;
}

//빈 칸이 없는 경우
bool move1(){
    switch(d){
        case 0:
            if(Room[r+1][c]!=1){
                r++;
                return true;
            }
        break;
        case 1:
            if(Room[r][c-1]!=1) {
                c--;
                return true;
            }
        break;
        case 2:
            if(Room[r-1][c]!=1) {
                r--;
                return true;
            }
        break;
        case 3:
            if(Room[r][c+1]!=1) {
                c++;
                return true;
            }
        break;
    }
    return false;
}

//빈 칸이 있는 경우
void move2(){
    switch(d){
        case 0:
            d=3;
            if(Room[r][c-1] == 0) c--;
        break;
        case 1:
            d=0;
            if(Room[r-1][c] == 0) r--;
        break;
        case 2:
            d=1;
            if(Room[r][c+1] == 0) c++;
        break;
        case 3:
            d=2;
            if(Room[r+1][c] == 0) r++;
        break;
    }
}
void Solve() {
    cin>>N>>M>>r>>c>>d;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>Room[i][j];
        }
    }   

    while(true){
        clean_room();
        if(check()) move2();
        else if(move1() == false) break;
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