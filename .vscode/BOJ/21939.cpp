#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define endl "\n"

using namespace std;

int N, M;
map<int, int> Difficulty;
multiset<pair<int,int>> Probs;

void Solve() {
    cin>>N;
    int p, l, x;
    for(int i=0; i<N; i++){
        cin>>p>>l;
        Probs.insert({l, p});
        Difficulty[p] = l;
    }

    cin>>M;
    string operation;
    
    while(M-->0){
        cin>>operation;
        if(operation == "add"){
            cin>>p>>l;
            Probs.insert({l,p});
            Difficulty[p] = l;
        }
        else if(operation == "recommend"){
            cin>>x; 
            if(x<0) cout<< (*Probs.begin()).second<<endl;
            else if(x>0) cout<<(*prev(Probs.end())).second<<endl;
        }
        else if(operation == "solved"){
            cin>>p;
            auto it = Probs.find({Difficulty[p], p});
            Probs.erase(it);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}