#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long getCount(string binary) {
    long long size = binary.size();
    long long count = 0;
    long long tmp = 1;
    while (size > count) {
        count += tmp;
        tmp *= 2;
    }
    return count;
}

bool check(string &s, int l, int r) {
    if (l == r) return true;
    int m = (l + r) / 2;
    char root = s[m];
    int left = (l + m - 1) / 2;
    int right = (m + 1 + r) / 2;
    if (root == '0' && (s[left] == '1' || s[right] == '1'))
        return false;
    return check(s, l, m - 1) && check(s, m + 1, r);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto num : numbers) {
        string binary = "";
        while (num > 0) {
            binary += to_string(num % 2);
            num /= 2;
        }
        reverse(binary.begin(), binary.end());
        long long count = getCount(binary);
        binary = string(count - binary.size(), '0') + binary;

        if (binary.empty()) answer.push_back(0);
        else answer.push_back(check(binary, 0, binary.size() - 1) ? 1 : 0);
    }
    return answer;
}
