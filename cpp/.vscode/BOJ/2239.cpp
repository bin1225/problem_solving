#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int SD[10][10];
vector<pair<int,int>> V;

bool check(int y, int x){
    for(int i=0; i<9; i++){
        if(i==x) continue;
        if(SD[y][i] == SD[y][x]) return false;
    }

    for(int i=0; i<9; i++){
        if(i==y) continue;
        if(SD[i][x] == SD[y][x]) return false;
    }

    int stx = (x/3)*3, sty = (y/3)*3;

    for(int i=sty; i<sty+3; i++){
        for(int j=stx; j<stx+3; j++){
            if(i == y && j == x) continue;
            if(SD[i][j] == SD[y][x]) return false;
        }
    }

    return true;
}

bool bt(int depth){
    if(depth>=V.size()){
        return true;
    }

    int x,y;
    x = V[depth].second; y = V[depth].first;
    
    for(int i=1; i<=9; i++){
        SD[y][x] = i;    
        if(check(y,x)) {
            if(bt(depth+1)) return true;
        }
    }
    SD[y][x] = 0;

    return false;
    
}
void Solve() {

    string s;
    for(int i=0; i<9; i++){
        cin>>s;
        for(int j=0; j<9; j++){
            SD[i][j] = s[j]-'0';
            if(SD[i][j]==0) V.push_back({i,j});
        }
    }

    bt(0);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<SD[i][j];
        }
        cout<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}