#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int answer;
vector<int> turn;

int calculate(vector<int> &choosed) {
    int dist[5];
    for(int i=1; i<=K; i++) dist[i] = 1;
    for(int i=0; i<N; i++) {
        dist[choosed[i]]+=turn[i];
    }
    
    int result = 0;
    for(int i=1; i<=K; i++) {
        if(dist[i] >= M) result++;
    }
    return result;
}

void chooseAndCalculate(vector<int>&choosed) {
    if(choosed.size() >= N) {
        answer = max(answer, calculate(choosed));
        return;
    }

    for(int i=1; i<=K; i++) {
        choosed.push_back(i);
        chooseAndCalculate(choosed);
        choosed.pop_back();
    }
}

int main() {
    cin>>N>>M>>K;
    turn.resize(N);
    for(int i=0; i<N; i++) {
        cin>>turn[i];
    }   

    vector<int> v;
    chooseAndCalculate(v);
    cout<<answer;
    return 0;
}