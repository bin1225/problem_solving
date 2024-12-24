#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl "\n"

using namespace std;

int N;
stack<pair<int, int>> stk;


void Solve() {
	int k;
	cin >> N;
	stk.push({ 1000000001,0 });
	for (int i = 1; i <= N; i++) {
		cin >> k;
		while (stk.top().first <k) {
			stk.pop();
		}
		cout << stk.top().second << " ";
		stk.push({ k,i });
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	Solve();
	return 0;
}
