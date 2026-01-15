#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

double getDist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}
void Solve() {
    int N; cin>>N;
    double x1,y1,r1,x2,y2,r2;

    for(int i=0; i<N; i++) {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double dist = getDist(x1,y1,x2,y2);
        //무한대인 경우
        if(x1==x2&&y1==y2&&r1==r2) cout<<-1<<endl;
        //0개인 경우
        else if(dist > r1 + r2 || dist + min(r1, r2) < max(r1, r2)) cout<<0<<endl;
        //1개인 경우
        else if(dist == r1 + r2 || dist + min(r1, r2) == max(r1, r2)) cout<<1<<endl;
        //2개인 경우
        else if(dist < r1 + r2 && dist + min(r1, r2) > max(r1, r2)) cout<<2<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}