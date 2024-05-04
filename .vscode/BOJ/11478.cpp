#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define endl "\n"

using namespace std;

set<string> S;

void Solve() {
    string input;
    cin>>input;

    for(int i=0; i<input.size(); i++){
        string s = "";
        for(int j=i; j<input.size(); j++){
            s+=input[j];
            S.insert(s);
        }
    }

    cout<<S.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}