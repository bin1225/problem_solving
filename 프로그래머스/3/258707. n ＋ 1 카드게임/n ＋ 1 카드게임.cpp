#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    
    vector<bool> my(n+1, false);
    vector<bool> passed(n+1, false);
    
    for(int i=0; i<n/3; i++) my[cards[i]] = true;
    
    for(int i=n/3; i+1<n; i+=2) {
        
        int card1, card2;
        card1 = cards[i]; card2 = cards[i+1];
        passed[card1] = passed[card2] = true;
        bool success = false;
        //손에 있는 카드로 해결
        for(int j=1; j<=n; j++) {
            if(my[j] && my[n+1-j]) {
                my[j] = false; my[n+1-j] = false; 
                success = true; 
                break;
            }
        }
        if(success) {answer++; continue;}
        
        //코인 1개 사용
        for(int j=1; j<=n; j++) {
            if(coin>=1 && my[j] && passed[n+1-j]) {
                coin--;
                my[j] = false; passed[n+1-j] = false; 
                success = true;
                break;
            }
        }
       
        if(success) {answer++; continue;}
        
        //코인 두개 사용
        for(int j=1; j<=n; j++) {
            if(coin>=2 && passed[j] && passed[n+1-j]) {
                coin-=2;
                passed[j] = false; passed[n+1-j] = false; 
                success = true;
                break;
            }
        }
       
        if(success) {answer++; continue;}
        else return answer;
    }
    return answer;
}