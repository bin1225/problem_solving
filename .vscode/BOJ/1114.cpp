    #define _CRT_SECURE_NO_WARNINGS
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <limits.h>

    #define endl "\n"

    using namespace std;

    int L,K,C;
    vector<int> V;
    int check(int l){

        int len, befo, now, cnt;
        len = 0; befo = 0; cnt = C;
        for(int i=0; i<V.size(); i++){
            now = V[i];

            if(now-befo>l) return -1;

            if(len+(now-befo)<=l){
                len+=(now-befo);
            }
            else{
                len = (now-befo);
                cnt--;
                if(cnt<0) return -1;
            }
            befo = now;
        }

        return cnt;
    }
    void Solve() {
        cin>>L>>K>>C;

        int a;
        for(int i=0; i<K; i++){
            cin>>a;
            V.push_back(a);
        }
        
        sort(V.begin(), V.end());
        V.push_back(L);

        int l,r,m, answer;
        l=1; r=L; answer=INT_MAX;
        while(l<=r){
            m=(l+r)/2;
            if(check(m)>=0) {
                r=m-1;
                answer = min(answer, m);
            }
            else l=m+1;
        }

        cout<<answer<<" ";

        if(check(answer)>0){
            cout<<V[0];
        }
        else{
            int len=0, befo = L, now, cut=V[0]; 
            for(int i=V.size()-1; i>=0; i--){
                now = V[i];
                if(len+(befo-now)==answer){
                    len = 0;
                    cut = now;
                }
                else if(len+(befo-now)>answer){
                    len = (befo-now);
                    cut = befo;
                }
                else {
                    len+=(befo-now);
                }
                befo = now;
            }
            
            cout<<cut;
        }
    }


    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        Solve();

        return 0;
    }