/**
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
 */
class Solution {
    public int reverse(int x) {
        if(x == 0) return 0;
        
        boolean isNegative = x<0 ? true: false;
        String stringValue = String.valueOf(x);
        char[] arr = stringValue.toCharArray();
        
        int idx = 0;
        while(arr[idx] == '0' || arr[idx] == '-') idx++;
        
        stringValue = stringValue.substring(idx);
        stringValue = new StringBuilder(stringValue).reverse().toString();
        
        if(isNegative) stringValue = "-" + stringValue;
        
        try { 
            return Integer.parseInt(stringValue);
        } catch(NumberFormatException e) {
            return 0;
        } 
        
    }
}
