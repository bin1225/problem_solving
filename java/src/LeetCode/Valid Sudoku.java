/**
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
 */

class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] colExist = new boolean[9][10];
        boolean[][] rowExist = new boolean[9][10];
        boolean[][][] boxExist = new boolean[3][3][10];

        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[i].length; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                if(colExist[j][num] || rowExist[i][num] || boxExist[i/3][j/3][num]) {
                    return false;
                }

                colExist[j][num] = true;
                rowExist[i][num] = true;
                boxExist[i/3][j/3][num] = true;
            }
        }

        return true;
    }
}
