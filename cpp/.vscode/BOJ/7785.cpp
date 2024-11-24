#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define endl "\n"

using namespace std;

int N;
map<string, bool> M;

void Solve() {
    cin>>N;
    string input[2];
    vector<string> answer;

    for(int i=0; i<N; i++){
        cin>>input[0]>>input[1];

        if(input[1] == "enter") M[input[0]] = true;
        else M[input[0]] = false;
    }

    for(auto m: M){
        if(m.second == true) answer.push_back(m.first);
    }

    for(int i=answer.size()-1; i>=0; i--) cout<<answer[i]<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}