#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int T, w, h;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

char Map[1010][1010];
queue<pair<int,int>> Q;
queue<pair<int,int>> FQ;


void spreadFire(){
    int size = FQ.size();
    int y, x, yy, xx;
    for(int i=0; i<size; i++){
        y = FQ.front().first; x = FQ.front().second;
        FQ.pop();
        for(int j = 0; j<4; j++){
                yy = y+dy[j]; xx = x+dx[j];
                
                if(yy<0 || yy>=h || xx<0||xx>=w) continue;
                if(Map[yy][xx] != '.') continue;
                Map[yy][xx] = '*'; 
                FQ.push({yy,xx});
            }
    }
}

void Solve() {
    cin>>w>>h;
    bool success = false;
    int x, y, xx, yy, size, answer=1;
    string input;
    pair<int,int> now;

    for(int i=0; i<h; i++){
        cin>>input;
        for(int j=0; j<w; j++){
            Map[i][j] = input[j];
            if(Map[i][j] == '@') Q.push({i,j});
            else if(Map[i][j] == '*') FQ.push({i,j});
        }
    }

    while(!Q.empty()){
        spreadFire();

        size = Q.size();
        for(int i=0; i<size; i++){
            now = Q.front(); Q.pop();
            y = now.first; x = now.second;

            for(int j = 0; j<4; j++){
                yy = y+dy[j]; xx = x+dx[j];
                if(yy<0 || yy>=h || xx<0||xx>=w) {
                    success = true;
                    break;
                }
                if(Map[yy][xx] != '.') continue;
                Map[yy][xx] = '@';
                Q.push({yy,xx});
            }
            if(success) break;
        }
        
        if(success) break;
        answer++;
    }

    if(success) cout<<answer<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    while(!Q.empty()) Q.pop();
    while(!FQ.empty()) FQ.pop();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    
    while(T-->0){
        Solve();
    }

    return 0;
}