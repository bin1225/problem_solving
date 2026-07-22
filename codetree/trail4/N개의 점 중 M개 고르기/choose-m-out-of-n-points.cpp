#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
int answer;
vector<pair<int,int>> points;
vector<pair<int,int>> selected_points;

int calculate_dist(pair<int,int> a, pair<int,int> b) {
    return (a.first - b.first) * (a.first - b.first) + 
            (a.second - b.second) * (a.second - b.second);
    //return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

void search(int idx) {
    if(selected_points.size() >= M) {
        int max_dist = 0;
        for(int i=0; i<M; i++) {
            for(int j=i+1; j<M; j++) {
                pair<int,int> a = selected_points[i];
                pair<int,int> b = selected_points[j];
                max_dist = max(max_dist, calculate_dist(a, b));
            }
        }

        answer = min(answer, max_dist);
        return;
    }

    for(int i=idx; i<N; i++) {
        selected_points.push_back(points[i]);
        search(i+1);
        selected_points.pop_back();
    }
}

int main() {
    answer = INT_MAX;
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        int y,x; cin>>y>>x;
        points.push_back({y,x});
    }

    search(0);
    cout<<answer;
    return 0;
}