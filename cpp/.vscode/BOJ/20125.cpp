#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define ll long long

using namespace std;

int N;
pair<int,int> heart;
char A[1010][1010];

void Solve() {
    
    cin>>N;
    string s;
    heart = {-1,-1};

    for(int i=1; i<=N; i++){
        cin>>s;
        for(int j=1; j<=N; j++){
            if(heart.first==-1 && s[j-1]=='*') heart = {i+1, j};
            A[i][j] = s[j-1];
        }
    }
    cout<<heart.first<<" "<<heart.second<<endl;
    int col, raw, len;
    //left arm
    raw = heart.second-1;
    col = heart.first;
    len = 0;
    while(raw>0 && A[col][raw] == '*'){
        raw--; len++;
    }
    cout<<len<<" ";

    //right arm
    raw = heart.second+1;
    col = heart.first;
    len = 0;
    while(raw<=N && A[col][raw] == '*'){
        raw++; len++;
    }
    cout<<len<<" ";

    //waist
    raw = heart.second;
    col = heart.first+1;
    len = 0;
    while(col<=N && A[col][raw] == '*'){
        col++; len++;
    }
    cout<<len<<" ";

    //left leg
    int leg_start = col;
    col = leg_start;
    raw = heart.second-1;
    len = 0;
    while(col<=N&&A[col][raw] =='*'){
        col++; len++;
    }
    cout<<len<<" ";

    //right leg
    col = leg_start;
    raw = heart.second+1;
    len = 0;
    while(col<=N&&A[col][raw] =='*'){
        col++; len++;
    }
    cout<<len<<" ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}