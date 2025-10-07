#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;
//서로 준 적이 있는 경우 -> 더 많이 준 사람이 받는다.
//아닌 경우 -> 선물지수가 더 높은 사람이 받는다.
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,pair<int,int>> hash; //first 다음달에 받을 개수, second 선물지수
    unordered_map<string,int> history;
    
    string give, receive;
    for(int i=0; i<gifts.size(); i++) {
        history[gifts[i]]++;

        istringstream iss(gifts[i]);
        iss>>give>>receive;
        
        hash[give].second ++;
        hash[receive].second--;
    }
    
    
    for(int i=0; i<friends.size()-1; i++) {
        for(int j=i+1; j<friends.size(); j++) {
            int history1 = history[friends[i] +" "+ friends[j]];
            int history2 = history[friends[j] +" "+ friends[i]];
            
            if(history1 != history2) {
                if(history1 > history2) {
                    hash[friends[i]].first++;
                }
                else if(history1 < history2) {
                    hash[friends[j]].first++;
                }
                
            }
            else if(history1 == history2){
                int giftscore1 = hash[friends[i]].second;
                int giftscore2 = hash[friends[j]].second;
                
                if(giftscore1 > giftscore2) {
                    hash[friends[i]].first++;
                }
                else if(giftscore1 < giftscore2) {
                    hash[friends[j]].first++;
                }
            }
            answer = max(answer, max(hash[friends[i]].first, hash[friends[j]].first));
            
        }
    }
    
    
    
    return answer;
}