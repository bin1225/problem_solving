#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> v; 
        int sum = 0;
        for(int i=0; i<gas.size(); i++) {
            int k = gas[i] - cost[i];
            sum+=k;
            v.push_back(k);
        }

        if(sum < 0) return -1;

        int max_gas = INT_MIN;
        int tmp = 0;
        int answer = 0;
        for(int i=v.size()-1; i>=0; i--) {
            tmp+=v[i];
            if(max_gas < tmp) {
                answer = i;
                max_gas = tmp;
            }
        }

        return answer;
    }
};