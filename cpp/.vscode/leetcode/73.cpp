class Solution {
public:
    
    void spread(int x, int y, vector<vector<int>>& matrix){
        
        int xx, yy;
        
        xx = x; yy = y;
        while(yy>=0){
            matrix[yy--][xx] = 0;
        }       
        
        xx = x; yy = y;
        while(xx>=0){
            matrix[yy][xx--] = 0;
        }
       
        xx = x; yy = y;
        while(yy<matrix.size()){
            matrix[yy++][xx] = 0;
        }
        
        xx = x; yy = y;
        while(xx<matrix[0].size()){
            matrix[yy][xx++] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> V;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0) V.push_back({i,j});
            }    
        }    
        
        for(int i=0; i<V.size(); i++){
            spread(V[i].second, V[i].first, matrix);
        }
    }
};