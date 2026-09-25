/**
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/879/
 */
class Solution {
    public void reverseString(char[] s) {
        int l,r;
        l = 0; r = s.length-1;

        while(l<r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++; r--;
        }
    }
}
