#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int N, C, M;
int cnt[2020];
struct Box{
    int start, end, count;
};

bool cmp(const Box& a, const Box& b){
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

void Solve() {
    cin>>N>>C>>M;
    vector<Box> V;

    int a,b,c, maxCount, availCount, answer=0;

    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        V.push_back({a,b,c});
    }

    sort(V.begin(), V.end(), cmp);

    for(int i=0; i<M; i++){
        
        maxCount = 0;
        for(int j = V[i].start; j<V[i].end; j++){
            maxCount = max(maxCount, cnt[j]);
        }

        availCount = min(V[i].count, C - maxCount);

        for(int j = V[i].start; j<V[i].end; j++){
            cnt[j]+=availCount;
        }
        answer+=availCount;
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