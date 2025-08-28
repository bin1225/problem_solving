#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> numrow[9];
        set<char> numcol[9];
        set<char> numbox[9];

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.') continue;

                char value = board[r][c];
                int boxIdx = (r/3) * 3 + (c/3);
                if(numrow[r].count(value) || numcol[c].count(value)||numbox[boxIdx].count(value)) return false;
                numrow[r].insert(value);
                numcol[c].insert(value);
                numbox[boxIdx].insert(value);
            }
        }

        return true;
    }
};