import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        
        List<String> A = new ArrayList<>();
        List<String> B = new ArrayList<>();
        
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        
        HashMap<String, Integer> hashA = new HashMap<>();
        HashMap<String, Integer> hashB = new HashMap<>();
        
        //문자열을 2글자씩 잘라서 hash에 개수 카운트
        for(int i=0; i<str1.length() - 1; i++) {
            char current = str1.charAt(i);
            char next = str1.charAt(i + 1);
            if(Character.isLetter(current) && Character.isLetter(next)){
                String s = ""+current+next;
                hashA.put(s, hashA.getOrDefault(s, 0) + 1);
            }
        }
        
        for (int i = 0; i < str2.length() - 1; i++) {
            char current = str2.charAt(i);
            char next = str2.charAt(i + 1);
            if (Character.isLetter(current) && Character.isLetter(next)){
                String s = "" + current + next;
                hashB.put(s, hashB.getOrDefault(s, 0) + 1);
            }
        }
        
        //교집합 개수
        int interSize=0;
        for(String s: hashA.keySet()) {
            interSize+= Math.min(hashA.get(s), hashB.getOrDefault(s,0));
        }
        
        //합집합 개수
        int sumSize=0;
        HashSet<String> allKeys = new HashSet<>(hashA.keySet());
        allKeys.addAll(hashB.keySet());
        
        for(String s: allKeys) {
            int countA = hashA.getOrDefault(s,0);
            int countB = hashB.getOrDefault(s,0);
            sumSize+=Math.max(countA,countB);
        }
        
        if(sumSize==0) answer = 65536;
        else answer = (int)((double)interSize/sumSize * 65536);
        
        return answer;
    }
}