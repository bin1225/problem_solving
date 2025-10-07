#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int check(int node, vector<vector<int>> &G, vector<bool> &visited) {
    if(G[node].size() == 0) {
        return 1;
    }
    
    int res = 0;
    for(int i=0; i<G[node].size(); i++) {
        int next = G[node][i];
        if(visited[next] == false) {
            visited[next] = true;
            res += check(next, G, visited);
        }
        else res+=2;
    }
    return res;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    vector<vector<int>> G(1010101);
    unordered_map<int,pair<int,int>> edgeCount; //in, out
    
    for(int i=0; i<edges.size(); i++) {
        G[edges[i][0]].push_back(edges[i][1]);
        edgeCount[edges[i][0]].second++;
        edgeCount[edges[i][1]].first++;
    }
    
    int n = edgeCount.size();
    int startNode = 0;
    for(int i=1; i<=n; i++) {
        if(edgeCount[startNode].second < edgeCount[i].second && edgeCount[i].first == 0){
            startNode = i;
        } 
    }
    //cout<<"start: "<<startNode;
    answer[0] = startNode;
    vector<bool> visited(n+1, false);
    for(int i=0 ; i<G[startNode].size(); i++) {
        int next = G[startNode][i];
        int res = check(next, G, visited);
        if(res == 1) answer[2]++;
        else if(res ==2) answer[1]++;
        else answer[3]++;
    }
    return answer;
}