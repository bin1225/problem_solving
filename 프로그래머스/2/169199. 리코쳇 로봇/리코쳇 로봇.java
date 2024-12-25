import java.util.*;

class Solution {
    public int solution(String[] board) {
        int answer = 0;
        int startX=-1, startY=-1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int rows = board.length;
        int cols = board[0].length();
        
        outerLoop:
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length(); j++){
                if(board[i].charAt(j) == 'R') {
                    startY = i;
                    startX = j;
                    break outerLoop;
                }
            }
        }
        
        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{startY, startX});
        visited[startY][startX] = true;
        
        while(!queue.isEmpty()){
            
            int size = queue.size();
            
            for(int j=0; j<size; j++){
                int[] current = queue.poll();
                
                int y = current[0];
                int x = current[1];
                
                
                if(board[y].charAt(x) == 'G') return answer;
                
                for(int i=0; i<4; i++){
                    int nx = x;
                    int ny = y;
                    
                     while (true) {
                        int tx = nx + dx[i];
                        int ty = ny + dy[i];

                        if (tx < 0 || tx >= cols || ty < 0 || ty >= rows || board[ty].charAt(tx) == 'D') {
                            break;
                        }

                        nx = tx;
                        ny = ty;
                    }

                    if (!visited[ny][nx] && (board[ny].charAt(nx) == '.' || board[ny].charAt(nx) == 'G')) {
                        visited[ny][nx] = true;
                        queue.add(new int[]{ny, nx});
                    }
                }
                
            }
            answer++;
                
            
        }
        
        
        return -1;
    }
}