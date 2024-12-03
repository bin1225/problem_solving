    #include<bits/stdc++.h>

    #define endl "\n"
    #define ll long long

    using namespace std;

    int matrix[101][101];
    int dy[] = {0,1,0,-1}; //우 하 좌 상
    int dx[] = {1,0,-1,0};

    int get_dir(int now, char turn){
        if(turn == 'D') now++;
        else if(turn == 'L') now--;
        
        if(now > 3) return 0;
        else if(now<0) return 3;
        else return now;
    }

    void Solve() {
        int N,K; cin>>N>>K;

        int r,c;
        for(int i=0; i<K; i++){
            cin>>r>>c;
            matrix[r][c] = 2;
        }

        int hy,hx; 
        hy = 1; hx = 1;
        queue<pair<int,int>> snake; snake.push({hy,hx});

        int L,X; char C;
        cin>>L;
        int time = 0, dir = 0;
        cin>>X>>C;
        while(true){
            time++;
            if(time > X&& L-->0) {
                dir = get_dir(dir,C);
                cin>>X>>C;
            }
            hy+=dy[dir]; hx+=dx[dir];
            //cout<<"time: "<<time<<" dir: "<<dir<<" y:"<<hy<<" x:"<<hx<<endl;
            if(hy>N||hx>N||hy<1||hx<1||matrix[hy][hx]==1) {
                cout<<time; return;
            }   

            //사과가 있으면 꼬리를 줄인다.
            if(matrix[hy][hx]!=2){
                matrix[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }

            matrix[hy][hx] = 1;
            snake.push({hy,hx});
        }

        
        return;
    }


    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        Solve();

        return 0;
    }