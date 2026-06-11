#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int result = 1;
    int month = m1, day = d1;
    while(true) {
        if(month == m2 && day == d2) break;

        result++; day++;

        if(day > days[month]) {
            month ++; day = 1;
        }
    }

    cout<<result;
    return 0;
}