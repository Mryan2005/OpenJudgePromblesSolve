#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, t, max, min;
	long long sum = 0;
	priority_queue<int, vector<int>, less<int>> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> m;
		for(int j = 1; j <= m; ++j) {
			cin >> t;
			q1.push(t);
			q2.push(t);
		}
		sum += q1.top() - q2.top();
		q1.pop();
		q2.pop();
	}
	cout << sum;
}
