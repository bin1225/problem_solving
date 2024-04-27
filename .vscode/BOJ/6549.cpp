#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl "\n"

using namespace std;

int N;
stack<pair<long long,long long>> st;

void Solve() {

    long long h, w, size=0, answer = 0;

    for(int i=0; i<N; i++){
        cin>>h;
        //입력받은 값이 스택의 맨 위 값보다 작은 경우, 더 큰 것들을 압축한다. 
        //(어차피 더 큰 것의 높이는 의미가 없다.)
        if(!st.empty() && st.top().first > h){
            w = 0;
            size = 0;
            while(!st.empty() && st.top().first > h){
                w+=st.top().second;
                size = max(size, st.top().first * w);
                st.pop();
            }
            answer = max(answer, size);
            st.push({h, w+1});
        }
        else{
            st.push({h,1});
        }
    }

    //마지막에 스택에 남아있는 것들을 처리한다.
    h = st.top().first;
    w = 0;
    while(!st.empty()){
        w+=st.top().second;
        size = max(size, st.top().first * w);
        st.pop();
    }
    answer = max(answer, size);
    
    cout<<answer<<endl;
    
    while(!st.empty()) st.pop();  
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    while(N!=0) {
        Solve();
        cin>>N;
    }

    return 0;
}