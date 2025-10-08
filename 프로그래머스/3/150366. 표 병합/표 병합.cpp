#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<vector<string>> chart(55, vector<string>(55,""));
vector<vector<pair<int,int>>> parent(55, vector<pair<int,int>>(55));

pair<int,int> findParent(int r, int c) {
    if(parent[r][c] == make_pair(r,c)) return {r,c};
    return parent[r][c] = findParent(parent[r][c].first, parent[r][c].second);
}

void merge(int r1, int c1, int r2, int c2) {
    if(r1==r2 && c1==c2) return;
    //cout<<"merge "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    
    pair<int,int> p1 = findParent(r1, c1);
    pair<int,int> p2 = findParent(r2, c2);
    // cout<<"p1:"<<p1.first<<" "<<p1.second<<endl;
    // cout<<"p2:"<<p2.first<<" "<<p2.second<<endl;
    string val1 = chart[p1.first][p1.second];
    string val2 = chart[p2.first][p2.second]; 
    
    if(val1.empty() && !val2.empty()) {
        chart[p1.first][p1.second] = val2;
    }
    parent[p2.first][p2.second] = p1;
}

void unmerge(int r, int c) {
    
    pair<int,int> p = findParent(r,c);
    string val = chart[p.first][p.second];
    vector<pair<int,int>> v;
    for(int i=0; i<parent.size(); i++) {
        for(int j=0; j<parent[i].size(); j++) {
            pair<int,int> pp = findParent(i,j);
            if(p == pp) v.push_back(make_pair(i,j));
        }
    }
    
    for(int i=0; i<v.size(); i++) {
        pair<int,int> pp = v[i];
        parent[pp.first][pp.second] = pp;
        chart[pp.first][pp.second] = "";
    }
    chart[r][c] = val;
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i=0; i<parent.size(); i++) for(int j=0; j<parent[i].size(); j++) parent[i][j] = {i,j};

    for(int i=0; i<commands.size(); i++) {
    
        istringstream ss(commands[i]);
        vector<string> cmd;
        string s;
        while(ss>> s) cmd.push_back(s);
        
        int r1, c1, r2, c2;
        string val1, val2;
        if(cmd[0] == "UPDATE" && cmd.size()==4) {
            r1 = stoi(cmd[1]); c1 = stoi(cmd[2]);
            val1 = cmd[3];
            pair<int,int> p = findParent(r1,c1);
            chart[p.first][p.second] = val1;
        }
        if(cmd[0] == "UPDATE" && cmd.size()==3) {
            val1 = cmd[1]; val2 = cmd[2];
            for(int i=0; i<chart.size(); i++) {
                for(int j=0; j<chart[i].size(); j++) {
                    if(chart[i][j] == val1) chart[i][j] = val2;
                }
            }
        }
        else if(cmd[0] == "MERGE") {
            r1 = stoi(cmd[1]); c1 = stoi(cmd[2]);
            r2 = stoi(cmd[3]); c2 = stoi(cmd[4]);
            merge(r1, c1, r2, c2);
        }
        else if(cmd[0] == "UNMERGE") {
            r1 = stoi(cmd[1]); c1 = stoi(cmd[2]);
            unmerge(r1,c1);
        }
        else if(cmd[0] == "PRINT") {
            r1 = stoi(cmd[1]); c1 = stoi(cmd[2]);
            pair<int,int> p = findParent(r1, c1);
            
            if(!chart[p.first][p.second].empty()) answer.push_back(chart[p.first][p.second]);
            else answer.push_back("EMPTY");
        }
    
    }
    
    return answer;
}