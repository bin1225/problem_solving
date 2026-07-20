#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;

vector<int> numbers;
vector<int> sequence;
map<int, pair<int,int>> location;

pair<int,int> S;
pair<int,int> E;

int answer;

int getDist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void search(int start_idx) {
    if(sequence.size() >= 3) {
        int dist = getDist(S, location[sequence[0]]);
        for(int i=1; i<sequence.size(); i++) {
            dist += getDist(location[sequence[i-1]], location[sequence[i]]);
        }
        dist += getDist(location[sequence[2]], E);
        answer = min(answer, dist);
        return;
    }

    for(int i=start_idx; i<numbers.size(); i++) {
        sequence.push_back(numbers[i]);
        search(i+1);
        sequence.pop_back();
    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        string s; cin>>s;
        for(int j=0; j<N; j++) {
            if(s[j] == 'S') S = {i,j};
            else if(s[j] == 'E') E = {i,j};
            else if(s[j] != '.') {
                numbers.push_back(s[j]-'0');
                location[s[j]-'0'] = {i,j};
            }
        }
    }

    sort(numbers.begin(), numbers.end());

    answer = INT_MAX;
    search(0);
    if(answer == INT_MAX) cout<<-1;
    else cout<<answer;
    return 0;
}