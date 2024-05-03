#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define endl "\n"

using namespace std;

int N, K;
map<string, int> HashMap;

bool cmp(const pair<string, int>& p1, const pair<string,int>& p2){
    return p1.second<p2.second;
}
void Solve() {

    cin>>K>>N;
    string input;
    for(int i=0; i<N; i++){
        cin>>input;
        HashMap[input] = i;
    }

    vector<pair<string, int>> V(HashMap.begin(), HashMap.end());
    sort(V.begin(), V.end(),cmp);
    
    for(int i=0; i<min(K,(int)V.size()); i++){
        cout<<V[i].first<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}