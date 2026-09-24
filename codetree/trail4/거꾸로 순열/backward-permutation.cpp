#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[11];
vector<int> answer;

void search() {
    if(answer.size() == N) {
        for(auto k: answer) cout<<k<<" ";
        cout<<endl;
        return;
    }

    for(int i=N; i>=1; i--) {
        if(visited[i] == true) continue;

        visited[i] = true;
        answer.push_back(i);
        search();
        answer.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin>>N;
    search();
    return 0;
}