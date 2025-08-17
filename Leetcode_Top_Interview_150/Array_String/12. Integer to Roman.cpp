#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> hash;
        hash[1] = 'I';
        hash[5] = 'V';
        hash[10] = 'X';
        hash[50] = 'L';
        hash[100] = 'C';
        hash[500] = 'D';
        hash[1000] = 'M';
        
        int tmp = 1000;
        string answer = "";
        while(tmp>0) {
            int k = num/tmp;
            if(k==9) {
                answer+=hash[tmp];
                answer+=hash[tmp*10]; 
                k = 0;
            }
            else if(k==4) {
                answer+=hash[tmp];
                answer+=hash[tmp*5]; 
                k = 0;
            }
            else if(k>=5) {
                answer += hash[tmp*5];
                k-=5;
            }

            for(int i=0; i<k; i++) {   
                answer += hash[tmp];
            }
            num %= tmp;
            tmp/=10;
        }
        return answer;
    }
};