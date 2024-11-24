class Solution {
public:
    int visited[101010];
    vector<int> G[101010];
    
    void Dfs(int n){
        int next;
        for(int i=0; i<G[n].size(); i++){
            next = G[n][i];
            if(visited[next] == 0){
                visited[next] = 1;
                Dfs(next);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n-1>connections.size()) return -1;
        
        int a, b, answer = 0;
        for(int i=0; i<connections.size(); i++){
            a = connections[i][0]; b = connections[i][1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                visited[i] = 1;
                Dfs(i); answer++;
            }    
        }
        
        return answer-1;
    }
};