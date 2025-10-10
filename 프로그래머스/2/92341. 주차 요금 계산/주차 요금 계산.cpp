#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

int calculateTime(string time) {
    
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    
    return hour * 60 + min;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> in, totalTime;
    
    string time, number, tmp;
    for(int i=0; i<records.size(); i++) {
    
        stringstream ss(records[i]);    
        ss>>time>>number>>tmp;
        
        int t = calculateTime(time);
        if(tmp == "IN") in[number] = t;
        else {
            totalTime[number] += t-in[number];
            in.erase(number);
        }
    }
    
    for(auto m: in) {
        totalTime[m.first] += (60*23 + 59)-m.second;
    }
    
    int amount;
    for(auto m: totalTime) {
        amount = fees[1];
        m.second -= fees[0];
        if(m.second > 0) amount += ceil((double)m.second/fees[2]) * fees[3];           answer.push_back(amount);        
    }
    
    
    return answer;
}