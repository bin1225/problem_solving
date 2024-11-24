#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

int N;
vector<pair<double,double>> Points;

void Solve() {
    cin>>N;

    double x,y,size=0;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        Points.push_back({x,y});
    }
    Points.push_back({Points[0].first, Points[0].second});
    
    for(int i=1; i<=N; i++){
        size+=(Points[i].first+Points[i-1].first)*(Points[i].second-Points[i-1].second);
    }

    size = round(10*abs(size/2.0))/10;
    printf("%.1lf", size);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}