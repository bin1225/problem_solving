#include <iostream>
#include <limits.h>
using namespace std;

int N;
int answer;

int A[11][11];
bool visited[11];

void search(int now, int cost, int cnt) {
    if(cnt >= N) {
        if(now != 0) return;
        answer = min(answer, cost);
        return;
    }

    for(int i=0; i<N; i++) {
        if(visited[i] == true) continue;
        if(A[now][i] == 0) continue;
        visited[i] = true;
        search(i, cost + A[now][i], cnt+1);
        visited[i] = false;
    }

}
int main() {
    // Please write your code here.
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
    }
    
    answer = INT_MAX;
    search(0, 0, 0);
    cout<<answer;
    return 0;
}