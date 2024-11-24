#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl "\n"

using namespace std;

int X, stick, sum;
vector<int> Sticks;

void Solve() {
    cin>>X;

    Sticks.push_back(64); sum = 64;

    int minStick;
    while(sum!=X){
        
        minStick = Sticks.back(); Sticks.pop_back(); 
        Sticks.push_back(minStick/2);

        sum = 0; 
        for(int k: Sticks) sum+=k;
        if(sum < X) Sticks.push_back(minStick/2);  
    }

    cout<<Sticks.size();
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}


