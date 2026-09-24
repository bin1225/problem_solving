#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

bool isPrime(string &number) {
    if(number.empty()) return false;
    long long n = stoll(number);
    if (n <= 1) return false;
    
    for(long long i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    return true;
    
}
int solution(int n, int k) {
    int answer = 0;
    string number = "";
    if(k==0) return answer;
    while(n>0) {
        n%k == 0 ? number+="0" : number += (n%k + '0');
        n/=k;
    }
    reverse(number.begin(), number.end());
    
    string token;
    istringstream is(number);
    while(getline(is, token, '0')){ 
        if(isPrime(token)) answer++;
    }
    return answer;
}