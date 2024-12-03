#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

int board[21][21];
int dice[7];
int x,y;
//0:바닥 1:우 2:좌 3:상 4:하

void dice_rolling(int command) {
	int temp = 0;
	temp = dice[0];
	switch (command) {
	case 1:
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
		break;
	case 2:
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
		break;
	case 3:
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
		break;
	case 4:
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
		break;
	}
}

void move(int command){
    switch (command) {
	case 1:
        y++;
        break;
	case 2:
        y--;
        break;
	case 3:
		x--;
        break;
	case 4:
        x++;
		break;
	}
}
void Solve() {
    int N,M,K;
    cin>>N>>M>>x>>y>>K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }

    int command;
    while(K-->0){
        cin>>command;
        if(command == 1 && y+1>=M) continue; 
        else if(command == 2 && y-1<0) continue;
        else if(command == 3 && x-1<0) continue; 
        else if(command == 4 && x+1>=N) continue;


        move(command);
        dice_rolling(command);

        if(board[x][y]==0) {board[x][y] = dice[5];}
        else {dice[5] = board[x][y]; board[x][y] = 0;}

        cout<<dice[0]<<endl;
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}