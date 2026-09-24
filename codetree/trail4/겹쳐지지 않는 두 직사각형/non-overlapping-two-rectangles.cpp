#include <iostream>

using namespace std;

int n, m;
int grid[5][5];

int sumNumbers(int x1, int y1, int x2, int y2) {
    int sum = 0;
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            sum+=grid[i][j];    
        }
    }
    return sum;
}

bool checkAvailable(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if(x2 < x3 || y2 < y3 || x4 < x1 || y4 < y1) return true;
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int answer = -1010101010;

    for(int y1=0; y1<n; y1++) {
        for(int x1=0; x1<m; x1++) {

            for(int y2=y1; y2<n; y2++) {
                for(int x2=x1; x2<m; x2++) {

                    for(int y3=0; y3<n; y3++) {
                        for(int x3=0; x3<m; x3++) {
                            
                            for(int y4=y3; y4<n; y4++) {
                                for(int x4=x3; x4<m; x4++) {
                                    if(checkAvailable(x1,y1,x2,y2,x3,y3,x4,y4)) {
                                        int s1 = sumNumbers(x1,y1,x2,y2);
                                        int s2 = sumNumbers(x3,y3,x4,y4);
                                        //cout<<s1<<" "<<s2<<endl;
                                        answer = max(answer, s1+s2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<answer;
    return 0;
}
