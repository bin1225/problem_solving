#include <string>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);

    int start=0, end=0, sum = sequence[0], len =INT_MAX;
    int size = sequence.size();
    while(end<size){
        
        if(k>sum){
            end++;
            if(end<size) sum+=sequence[end];
        }
        else if(k<sum){
            sum-=sequence[start];
            start++;
        }
        else if(k==sum){
            if(len> (end-start)+1){
                len = (end-start)+1;
                answer[0] = start;
                answer[1] = end;
            }
            end++; if(end<size) sum+=sequence[end];
        }
    }
    return answer;
}