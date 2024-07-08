#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, M;
vector<long long> gitars;

int bit_cnt(long long x){
    int cnt = 0;
    for(int i=0; i<max(N,M); i++){
        cnt+= (x>>i) & 1;
    }
    return cnt;
}
void Solve() {
    cin>>N>>M;

    int answer = 0, maxSongCnt=0;
    long long bitmask;
    string name, s;
    for(int i=0; i<N; i++){
        cin>>name>>s;
        bitmask = 0;
        for(int j=0; j<M; j++){
            bitmask = (bitmask<<1) | (s[j] == 'Y');
        }

        gitars.push_back(bitmask);
    }

    long long songs = 0;
    int gitarCnt, songCnt;
    
    for(int comb=0; comb<(1<<N); comb++){

        songs = 0;
        for(int i=0; i<N; i++){
            if(comb & (1<<i)){
                songs|=gitars[i];
            }
        }
        gitarCnt = bit_cnt(comb);
        songCnt = bit_cnt(songs);

        if(maxSongCnt<songCnt) {
            maxSongCnt = songCnt;
            answer = gitarCnt;
        }
        else if(maxSongCnt == songCnt && answer > gitarCnt) answer = gitarCnt;
        
    }
    if(maxSongCnt!=0)cout<<answer;
    else cout<<-1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}