#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n = id_list.size();
    vector<vector<int>> count(n, vector<int>(n,0));
    unordered_map<string, int> idx;
    vector<bool> check(n,false);
    
    for(int i=0; i<n; i++) {
        idx[id_list[i]] = i;
    }
    
    
    string s1, s2;
    int idx1, idx2;
    for(int i=0; i<report.size(); i++) {
        istringstream is(report[i]);
        is>>s1>>s2;
        idx1 = idx[s1]; idx2 = idx[s2];
        
        count[idx1][idx2] = 1;
    }
    
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            cnt+=count[j][i];
        }
        if(cnt >= k) check[i] = true;
    }
    
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(count[i][j] && check[j]) cnt++;       
        }
        answer.push_back(cnt);
    }
    return answer;
}