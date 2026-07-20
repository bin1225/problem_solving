#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer;
vector<int> numbers;
int A[22];

void search(int cnt, int idx) {
    if(cnt >= M) {
        int result = A[0];
        for(int i=1; i<M; i++) {
            result = result xor A[i];
        }
        answer = max(answer, result);
        return;
    }

    for(int i=idx; i<numbers.size(); i++) {
        A[cnt] = numbers[i];
        search(cnt+1, i+1);
    }
}

int main() {
    cin>>N>>M;

    for(int i=0; i<N; i++) {
        int n; cin>>n;
        numbers.push_back(n);
    }

    search(0, 0);
    cout<<answer;

    return 0;
}