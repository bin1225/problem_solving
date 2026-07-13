#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string answer;

bool checkAvailable(string number) {
    int ans_len = number.length();

    for(int len=1; len<=number.size()/2; len++) {
        string a = number.substr(ans_len-len, len);
        string b = number.substr(ans_len-len*2, len);
        if(a==b) return false;
    } 

    return true;
}

bool dfs(string number) {
    if(number.length() == N) {
        if(answer == "" || checkAvailable(number)) {
            answer = number;
            return true;
        }
    }

    for(int num = 4; num<=6; num++) {
        if(!checkAvailable(number+to_string(num))) continue;
        if(dfs(number+to_string(num))) {
            return true;
        }
    }

    return false;;
}

int main() {
    cin>>N;

    dfs("");

    cout<<answer;
    return 0;
}
