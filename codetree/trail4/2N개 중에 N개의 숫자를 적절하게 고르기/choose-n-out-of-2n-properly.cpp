#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int N; 
vector<int> numbers;

int answer;
bool selected[22];

void search(int start_idx, int cnt) {
    if(cnt == N) {
        int result = 0;
        for(int i=0; i<N*2; i++) {
            if(selected[i]) result += numbers[i];
            else result -= numbers[i];
        }
        answer = min(answer, abs(result));
        return;
    }

    for(int i=start_idx; i<2*N; i++) {
        selected[i] = true;
        search(i+1, cnt+1);

        selected[i] = false;
        search(i+1, cnt);
    }
}

int main() {
    cin>>N;

    for(int i=0; i<2*N; i++) {
        int n; cin>>n;
        numbers.push_back(n);
    }    

    answer = INT_MAX;
    search(0,0);
    
    cout<<answer;
    return 0;
}