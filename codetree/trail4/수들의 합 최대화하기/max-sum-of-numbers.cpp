#include <iostream>
#include <cstring>

using namespace std;

int N; 
int answer;
int A[11][11];

int selected_col[11];

void choose(int row) {
    if(row == N) {
        int result = 0;
        for(int i=0; i<N; i++) {
            result += A[selected_col[i]][i];
        }

        answer = max(answer, result);
        return;
    }

    for(int i=0; i<N; i++) {
        if(selected_col[i] >= 0) continue;

        selected_col[i] = row;
        choose(row+1);
        selected_col[i] = -1;
    }
}
int main() {

    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }

    memset(selected_col, -1, sizeof(selected_col));
    choose(0);
    cout<<answer;
    return 0;
}