class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int pre[10101];
        int now = 0, answer = 0;
        
        pre[0]=0;
        for(int i=0;i<hours.size(); i++){
            if(hours[i]>8) now++;
            else now--;
            pre[i+1]=now;
            //cout<<now<<" ";
        }
        
        for(int i=0; i<hours.size(); i++){
            for(int j= hours.size(); j>i;j--){
                if(j-i<answer) break;
                
                if(pre[j]-pre[i]>0) answer = max(answer, j-i);
                
            }
        }
    
        
        return answer;
    }
};