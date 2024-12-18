#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;
int N,M,H;
int A[33][13];

bool simulate(){
    int x,y;
    for(int i=1; i<=N; i++){
        x=i; 
        for(y=1; y<=H; y++){
            if(A[y][x]==1) x++;
            else if(A[y][x-1]==1) x--;
        }
        if(x!=i) return false;
    }
    return true;
}

int run(int cnt, int y, int x) {
    if (simulate()) return cnt;
    if (cnt == 3) return INT_MAX;

    int result = INT_MAX;
    for (int i = y; i <= H; i++) {
        for (int j = (i == y ? x : 1); j < N; j++) {
            // Check if we can place a ladder here
            if (A[i][j] == 1 || A[i][j - 1] == 1 || A[i][j + 1] == 1) continue;

            A[i][j] = 1; // Place ladder
            result = min(result, run(cnt + 1, i, j + 2)); // Move right to avoid overlap
            A[i][j] = 0; // Backtrack

            if (result == cnt + 1) return result; // Early exit
        }
    }
    return result;
}

void Solve() {
    cin>>N>>M>>H;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        A[a][b] = 1;
    }

    int answer = run(0, 1, 1);
    cout << (answer == INT_MAX ? -1 : answer) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}