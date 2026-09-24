#include <iostream>
#include <vector>
using namespace std;

int N;

int selected[10];

void search(int sequence) {
    if(sequence > N) {
        vector<int> numbers(10,0);
        for(int i=1; i<=N; i++) {
            int seq = selected[i];
            numbers[seq] = i;
        }

        for(int i=1; i<=N; i++) {
            cout<<numbers[i]<<" ";
        }
        cout<<endl; 

        return;
    }

    for(int i=1; i<=N; i++) {
        if(selected[i] == 0) {
            selected[i] = sequence;
            search(sequence+1);
            selected[i] = 0;
        }
    }


}
int main() {

    cin>>N;
    search(1);
    return 0;
}