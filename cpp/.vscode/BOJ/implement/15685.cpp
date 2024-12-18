#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;
int A[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
vector<int> directions;
void get_directions(int d, int g){

    directions.push_back(d);
    while(g-->0){
        int size = directions.size();
        for(int i=size-1; i>=0; i--){
            directions.push_back((directions[i]+1)%4);
        }
    }
}

void check(int x, int y){
    int dir;
    for(int i=0; i<directions.size(); i++){
        A[y][x] = 1;
        dir = directions[i];
        y+=dy[dir]; x+=dx[dir];
    }
    A[y][x] = 1;
}

void Solve() {
    int N; cin>>N;
    int x,y,d,g;
    for(int i=0; i<N; i++){
        cin>>x>>y>>d>>g;
        directions.clear();
        get_directions(d, g); 
        check(x,y);
    }

    int answer = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(A[i][j]==1 && A[i+1][j]==1 && A[i][j+1]==1 && A[i+1][j+1]==1) answer++;
        }
    }
    cout<<answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}