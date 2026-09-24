#include <iostream>
using namespace std;

int main() {
    int day, hour, min;
    int A, B, C; cin>>A>>B>>C;

    day = hour = min = 11;
    int answer = 0;

    if(A < day) {cout<<-1; return 0;}
    if(A == day && hour > B) {cout<<-1; return 0;}
    if(A == day && hour == B && min > C) {cout<<-1; return 0;}

    while(true) {
        if(day == A && hour == B && min == C) break;

        min++;
        answer++;

        if(min >= 60) {
            hour++;
            min = 0;
        }

        if(hour >= 24) {
            day++;
            hour = 0;
        }
    }

    cout<<answer; 
    return 0;
}