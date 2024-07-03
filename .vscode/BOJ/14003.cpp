#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
int befoIdx[1010101];
vector<int> V;
vector<pair<int,int>> LIS;
void Solve() {
    cin>>N;

    int num, idx, left, right, mid, befo;
    for(int i=0; i<N; i++){
        cin>>num; V.push_back(num);
    }


    for(int i=0; i<N; i++){

        if(LIS.empty()||V[i]> LIS.back().first){
            
            if(LIS.empty()) befoIdx[i] = -1;
            else befoIdx[i] = LIS.back().second;
            LIS.push_back({V[i], i}); 
            continue;
        }
                
        left = 0; right = LIS.size()-1;
        mid = (left+right)/2; 

        while(left<right){
            mid = (left+right)/2;
            
            
            if(V[i]>LIS[mid].first) left = mid+1;
            else if(V[i]<LIS[mid].first) right = mid;
            else break;
        }
        if(V[i]>LIS[mid].first) mid++;
        
        LIS[mid] = {V[i], i};
        if(mid!=0) befoIdx[i] = LIS[mid-1].second;
        else befoIdx[i] = -1;
    }


    cout<<LIS.size()<<endl;
    vector<int> answer;
    befo = LIS.back().second;
    while(befo!=-1){
        answer.push_back(V[befo]);
        befo = befoIdx[befo];
    }

    for(int i=answer.size()-1; i>=0; i--) cout<<answer[i]<<" ";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}