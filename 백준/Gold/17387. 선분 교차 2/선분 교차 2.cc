#include<bits/stdc++.h>

#define endl "\n"
#define ll long long

using namespace std;

#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

bool overlap(Point a, Point b, Point c, Point d) {
    if (max(a.x, b.x) < min(c.x, d.x)) return false;
    if (max(c.x, d.x) < min(a.x, b.x)) return false;
    if (max(a.y, b.y) < min(c.y, d.y)) return false;
    if (max(c.y, d.y) < min(a.y, b.y)) return false;
    return true;
}

int sign(long long x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

bool isIntersect(Point a, Point b, Point c, Point d) {
    long long ab_c = ccw(a, b, c);
    long long ab_d = ccw(a, b, d);
    long long cd_a = ccw(c, d, a);
    long long cd_b = ccw(c, d, b);

    int s1 = sign(ab_c);
    int s2 = sign(ab_d);
    int s3 = sign(cd_a);
    int s4 = sign(cd_b);

    if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) {
        return overlap(a, b, c, d);
    }

    return (s1 * s2 <= 0) && (s3 * s4 <= 0);
}


void Solve() {

    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    cout << isIntersect(p1, p2, p3, p4);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}