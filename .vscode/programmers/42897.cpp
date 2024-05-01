#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp1[1010101][2];
long long dp2[1010101][2];

long long solution(vector<int> money) {
    long long answer = 0;
    int msize = money.size();
    
    dp1[0][1] = money[0];
    for(int i=1; i<money.size()-1;i++){
        dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1]);
        
        dp1[i][1] = dp1[i-1][0] + money[i];
    }
    
    for(int i=1; i<money.size();i++){
        dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]);
        
        dp2[i][1] = dp2[i-1][0]+money[i];

    }
    
    
     answer = max(dp1[msize-2][0], dp1[msize-2][1]);
    answer =max(answer, max(dp2[msize-1][0], dp2[msize-1][1]));
    cout<<answer;
    return answer;
}