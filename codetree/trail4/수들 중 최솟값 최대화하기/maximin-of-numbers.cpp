#include <iostream>
#include <map>

using namespace std;

int n, answer;
int grid[10][10];

bool selected_col[10];
map<int,int> col;

void choose(int row) {
    if(row == n) {
        int min_num = 10101;
        
        for(int i=0; i<n; i++) {
            min_num = min(min_num, grid[i][col[i]]);
        }
        answer = max(answer, min_num);
        return;
    }

    for(int i=0; i<n; i++) {
        if(selected_col[i]) continue;
        
        selected_col[i] = true;
        col[row] = i;
        choose(row+1);
        selected_col[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    choose(0);
    cout<<answer;
    return 0;
}
