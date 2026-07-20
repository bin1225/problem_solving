#include <iostream>
#include <vector>

using namespace std;

int N, M;

void search(vector<int> &V, int last) {
    if(V.size() >= M) {
        for(int num: V) {
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=last+1; i<=N; i++) {
        V.push_back(i);
        search(V, i);
        V.pop_back();
    }
    return;
}
int main() {
    cin>>N>>M;
    vector<int> V;
    search(V, 0);
    return 0;
}