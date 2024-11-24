#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

#define endl "\n"

using namespace std;

int N, S, E, Q;
unordered_map<string, bool> check;

int timeToNum(string s){
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,5));
}
void Solve() {
    int time, answer = 0;
    string s, e, q, input, name;
    cin>>s>>e>>q;
    S = timeToNum(s);
    E = timeToNum(e);
    Q = timeToNum(q);

    while(cin>>input>>name){
        time = timeToNum(input);

        if(time <= S) check[name] = true;
        else if(time>=E && time<= Q && check[name]) {
            answer++;
            check[name] = false;
        }
        
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