#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

class Time
{
public:
    int start;
    int end;

    bool operator<(const Time& t) {
        if(end == t.end)
            return start < t.start;
        return end < t.end;
    }
    Time(int s, int e) : start(s), end(e) {}
};

void Solve() {

    int N;
    cin >> N;

    vector<Time> times;
    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        times.emplace_back(s,e);
    }
    
    sort(times.begin(), times.end());

    int answer = 0;
    int canStart = 0;
    for (int i = 0; i < N; i++) {
        if(times[i].start >= canStart) {
            //cout << times[i].start << " " << times[i].end << endl;
            canStart = times[i].end;
            answer++;
        }
    }
    cout << answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}