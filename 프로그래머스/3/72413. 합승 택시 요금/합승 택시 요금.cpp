#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 202020202;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 202020202));
    vector<vector<int>> G(n+1);         
    for(auto v: fares){
        dist[v[0]][v[1]] = v[2];
        dist[v[1]][v[0]] = v[2];
    }
    for(int i=1; i<=n; i++) dist[i][i] = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            
            for(int k=1; k<=n; k++){
                
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        answer = min(answer, dist[i][s] + dist[i][a] + dist[i][b]);   
    }
    return answer;
}