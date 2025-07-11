import java.util.*;

class Solution {
    public int[] solution(String msg) {
        List<Integer> answerList = new ArrayList<>();
        Map<String,Integer> dic = new HashMap<>();
        
        for(int i=0; i<26; i++) {
            dic.put(String.valueOf((char)('A'+i)), i+1);
        }
        
        int idx = 27;
        for(int i=0; i<msg.length();) {
            String s = String.valueOf(msg.charAt(i));
            
            int j = i+1;
            while(j<msg.length() && dic.containsKey(s+msg.charAt(j))) {
                s+=msg.charAt(j);
                j++;
            }
            
            answerList.add(dic.get(s));   
            
            if(j<msg.length()) {
                dic.put(s+msg.charAt(j), idx++);      
            }
            
            i=j;
        }
        
        int[] answer = new int[answerList.size()];
        for (int k = 0; k < answerList.size(); k++) {
            answer[k] = answerList.get(k);
        }
        
        return answer;
    }
}