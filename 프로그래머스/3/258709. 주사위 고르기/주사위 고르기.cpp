#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getResults(vector<vector<int>> &dices, vector<int> &choice, vector<int> &result, int idx, int sum) {
    if(idx>=choice.size()) {
        result.push_back(sum);
        return;
    } 
    
    vector<int> dice = dices[choice[idx]];
    for(int i=0; i<dice.size(); i++) {
        int num = dice[i];
        getResults(dices, choice, result, idx+1, sum+num);
    }
    
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int winMax = 0;
    
    int n = dice.size();
    vector<int> choice1;
    vector<int> choice2;
    vector<bool> choice(n, false);
    for(int i=0; i<n/2; i++) choice[i] = true;
    sort(choice.begin(), choice.end());
    
    do {
        choice1.clear(); choice2.clear();
        
        for(int i=0; i<choice.size(); i++) {
            if(choice[i]) choice1.push_back(i);
            else choice2.push_back(i);
        }
        
        vector<int> results1;
        vector<int> results2;
        
        getResults(dice, choice1, results1, 0, 0);
        getResults(dice, choice2, results2, 0, 0);
        
        sort(results1.begin(), results1.end());
        sort(results2.begin(), results2.end());
        
        int winCount = 0;
        for(int i=0; i<results2.size(); i++) {
            auto idx = upper_bound(results1.begin(), results1.end(), results2[i]);  
            winCount+= results1.size() - (idx-results1.begin());
        }
        
        if(winMax < winCount) {
            winMax = winCount;
            for(int i=0; i<choice1.size(); i++) choice1[i]++;
            answer = choice1;
        }
    } while(next_permutation(choice.begin(), choice.end()));
    return answer;
}