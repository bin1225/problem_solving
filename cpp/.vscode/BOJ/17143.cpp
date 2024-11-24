#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define endl "\n"

using namespace std;

int R,C,M,r,c,s,d,z, answer;
int Map[101][101];
struct Shark{
    int r,c;
    int speed;
    int dir;
    int size;
};

map<int, Shark> sharks;
vector<int> todo;
void Solve() {
    cin>>R>>C>>M;
    fill(&Map[0][0], &Map[R][C+1], -1);

    for(int i=1; i<=M; i++){
        cin>>r>>c>>s>>d>>z;
        Map[r][c] = i;
        if(d ==1||d==2) s%=(R*2-2);
        else s%=(C*2-2);
        sharks[i] = {r,c,s,d,z};    
    }

    int now = 0;

    while(now<C){
        //1. 낚시꾼이 오른쪽으로 한 칸 이동한다.
        now++; 
        
        //2. 땅과 가장 가까운 상어를 잡는다. 
        for(int i=1; i<=R; i++){
            if(Map[i][now]!=-1){
                answer+=sharks[Map[i][now]].size;
                sharks.erase(Map[i][now]);
                Map[i][now] = -1;
                break;
            }
        }

        //3. 상어가 이동한다.
        for(auto s: sharks){
            Shark shark = s.second;
            Map[shark.r][shark.c] = -1;
            int dist = shark.speed;
            while(dist-->0){
                if(shark.dir == 1){
                    shark.r--;
                    if(shark.r<1) {shark.r = 2; shark.dir = 2;}
                }
                else if(shark.dir==2){
                    shark.r++;
                    if(shark.r>R) {shark.r = R-1; shark.dir = 1;}
                }
                else if(shark.dir ==3){
                    shark.c++;
                    if(shark.c>C) {shark.c = C-1; shark.dir = 4;}
                }
                else if(shark.dir ==4){
                    shark.c--;
                    if(shark.c<1) {shark.c = 2; shark.dir = 3;}
                }
            }

            sharks[s.first] = shark;
        }

        //같은 칸에 상어가 두마리 이상 존재하는 경우 더 큰 상어가 잡아먹는다.
        todo.clear();   //잡아먹힐 상어의 번호를 todo 배열에 저장
        for(auto s: sharks){
            Shark shark = s.second;
            if(Map[shark.r][shark.c]==-1) Map[shark.r][shark.c] = s.first;
            else if(sharks[Map[shark.r][shark.c]].size < shark.size) {
                todo.push_back(Map[shark.r][shark.c]);
                Map[shark.r][shark.c] = s.first;
            }
            else {
                todo.push_back(s.first);
            }

        }
        for(int k: todo) sharks.erase(k);
    }

    cout<<answer;
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}