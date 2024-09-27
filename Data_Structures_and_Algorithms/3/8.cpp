#include <bits/stdc++.h>
using namespace std;
int N, K;
int record[100060];

int solve() {
	queue<pair<int, int>> Q;
	int cur = N;
	pair<int, int> step;
	Q.push({cur, 0});
	while(!Q.empty()) {
		step = Q.front();
		Q.pop();
		record[step.first] = 1;
		if(step.first == K) return step.second;
		if(step.first < K && record[step.first+1] == 0) Q.push({step.first+1, step.second+1});
		if(step.first > 0 && record[step.first-1] == 0) Q.push({step.first-1, step.second+1});
		if(step.first*2 < 100000 && record[step.first*2] == 0) Q.push({step.first*2, step.second+1});
	}
}

int main() {
	scanf("%d %d", &N, &K);
	int res = solve();
	printf("%d", res);
}
