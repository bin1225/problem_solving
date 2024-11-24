#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl "\n"

using namespace std;

int N, M;
pair<int,int> ProbInfo[101010];
set<pair<int,int>> Algo[101];
set<pair<int,int>> Diff;

void Solve() {
    cin>>N;
    int p, l, g, x;

    for(int i=0; i<N; i++){
        cin>>p>>l>>g;
        ProbInfo[p] = {l,g};
        Algo[g].insert({l, p});
        Diff.insert({l,p});
    }

    cin>>M;

    string op;
    for(int i=0; i<M; i++){
        cin>>op;

        if(op =="recommend"){
            cin>>g>>x;
            if(x==1) cout<< (*prev(Algo[g].end())).second<<endl;
            else cout<<(*Algo[g].begin()).second<<endl;
        }
        else if(op == "recommend2"){
            cin>>x;
            pair<int,int> resultProb;
            if(x==1) resultProb = *prev(Diff.end());
            else resultProb = *Diff.begin();
            cout<<resultProb.second<<endl;
        }
        else if(op=="recommend3"){
            cin>>x>>l;
            auto iter = Diff.lower_bound({l,0});

            if(x==1){
                if((*iter).first >= l) cout<<(*iter).second<<endl;
                else cout<<-1<<endl;
            }
            else{
                if((*iter) == *Diff.begin()) cout<<-1<<endl;
                else cout<< (*prev(iter)).second<<endl;
            }
        }
        else if(op=="add"){
            cin>>p>>l>>g;        
            ProbInfo[p] = {l,g};
            Algo[g].insert({l, p});
            Diff.insert({l,p});
        }
        else if(op=="solved"){
            cin>>p;
            Algo[ProbInfo[p].second].erase({ProbInfo[p].first, p}); 
            Diff.erase({ProbInfo[p].first,p});
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