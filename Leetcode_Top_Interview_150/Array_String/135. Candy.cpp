#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total_candy = n;
        int i = 1;
        
        while(i<n) {
            if(ratings[i] == ratings[i-1]) {
                i++; continue;
            }

            int peak = 0;
            while(i<n && ratings[i] > ratings[i-1]) {
                i++; peak++;
                total_candy+=peak; 
            }   

            if(i == n) return total_candy;
            int vally = 0;
            while(i<n && ratings[i] < ratings[i-1]) {
                i++; vally++;
                total_candy+=vally; 
            }   
            total_candy-=min(peak, vally);
        }

        return total_candy;
    }
};