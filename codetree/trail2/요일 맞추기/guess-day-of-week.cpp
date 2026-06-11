#include <iostream>
using namespace std;

bool isAfter(int m1, int d1, int m2, int d2) {
    if(m1 < m2 || (m1 == m2 && d1 < d2)) return true;
    return false;
}

int main() {
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dayOfWeek[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    bool b = isAfter(m1, d1, m2, d2);
    int dow = 0;
    int month = m1, day = d1;
    while(true) {
        if(month == m2 && day == d2) break;

        if(b) {
            day++;
            dow++;
        }
        else {
            day--;
            dow--; if(dow < 0) dow = 6;
        }

        if(b && day > days[month]) {
            month ++; day = 1;
        }
        if(!b&& day == 0) {
            month--; day = days[month];
        }
    }

    cout<<dayOfWeek[dow%7];
    return 0;
}

