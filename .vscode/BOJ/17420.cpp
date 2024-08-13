#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n"
#define ll long long

using namespace std;

int N;
ll A[101010];
ll B[101010];
vector<pair<ll,ll>> V;

void Solve() {
    cin>>N;
    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=0; i<N; i++) cin>>B[i];

    for(int i=0; i<N; i++){
        V.push_back({B[i],A[i]});
    }
    
    sort(V.begin(), V.end());
    
    ll answer=0, beforMaxDay=0;

    for(int i=0; i<V.size(); i++){
        
        ll maxDay = 0, resultDay, cnt;
        
        //사용 날짜가 같은 경우는 한 번에 처리한다.
        int idx = i;
        while(idx<V.size()){
            if(V[idx].first != V[i].first) {idx--; break;}  //사용날짜가 다른 경우 

            //기한이 사용 날짜보다 더 많이 남은 경우
            if(V[idx].second>=max(beforMaxDay, V[idx].first)) {
                maxDay = max(maxDay, V[idx].second);
                idx++;
                continue;
            }    

            cnt = ceil((max(beforMaxDay,V[idx].first)-V[idx].second)/30.0);
            answer+=cnt;
            resultDay = V[idx].second + cnt*30;
            maxDay = max(maxDay, resultDay);
            idx++;
        }
        //사용날짜가 같은 경우를 모두 확인 후 beforeMaxDay를 업이트
        i = idx;
        beforMaxDay = maxDay;
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