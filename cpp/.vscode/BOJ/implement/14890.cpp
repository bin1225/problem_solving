#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int N,L;
int A[101][101];
vector<vector<int>> V;

void getRoads(){
    for(int i=0; i<N; i++){
        vector<int> c;
        vector<int> r;
        for(int j=0; j<N; j++){
            r.push_back(A[i][j]);
            c.push_back(A[j][i]);
        }
        V.push_back(c);
        V.push_back(r);
    }
}

bool can_go(vector<int> v){
    int now = 0;
    int check[N]; for(int i=0; i<N; i++) check[i] = 0;
    while(now<N-1){
        if(v[now] == v[now+1]) now++;
        else if(v[now]<v[now+1]){
            if(abs(v[now]-v[now+1])>1) return false;
            int tmp = now;
            while(tmp>=0 && v[tmp]==v[now]&&check[tmp]==0&&now-tmp<L){
                check[tmp] =1; tmp--;
            }
            if(now-tmp!=L) return false;
            else now++;
        }
        else {
            if(abs(v[now]-v[now+1])>1) return false;
            now++;
            int tmp = now;
            while(tmp<N && v[tmp]==v[now]&&check[tmp]==0&&tmp-now<L){
                check[tmp] =1; tmp++;
            }
            if(tmp-now!=L) return false;
        }
    }
    return true;
}

void Solve() {
    cin>>N>>L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>A[i][j];
        }   
    }

    getRoads();
    int answer=0;
    for(int i=0; i<V.size(); i++){
        if(can_go(V[i])) answer++;
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