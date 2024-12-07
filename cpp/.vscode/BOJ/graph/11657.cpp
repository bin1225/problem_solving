#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

struct Link{
    int a,b,c;
};

void Solve() {
    int N,M; cin>>N>>M;
    int a,b,c;
    vector<Link> V;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        V.push_back({a,b,c});
    }

    ll dist[N+1]; 
    fill(dist, dist+N+1, INT_MAX);
    dist[1] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<V.size(); j++){
            Link l = V[j];
            if(dist[l.a] == INT_MAX) continue;
            if(dist[l.a]+l.c < dist[l.b]) {
                if(i==N-1){
                    cout<<-1; return;
                }
                dist[l.b] = dist[l.a]+l.c;
            }
        }
    }

    for(int i=2; i<=N; i++){
        if(dist[i] == INT_MAX) cout<<-1<<endl;
        else cout<<dist[i]<<endl;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}