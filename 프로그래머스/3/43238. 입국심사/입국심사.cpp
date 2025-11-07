#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional> // for greater
using namespace std;

long long solution(int n, vector<int> times) {
    

    long long l,r;
    l = 0; r = 1e17;
    long long answer = 1e17;
    
    while(l<=r) {
        long long m = l + (r-l)/2;
        long long count = 0;
        for(int i=0; i<times.size(); i++) {
            count += m/times[i];
            if(count >= n) break;
        }
        
        if(count >= n) {
            r = m-1;
            answer = min(answer, m);
        }
        else if(count < n) l = m+1;
    }
    return answer;
}