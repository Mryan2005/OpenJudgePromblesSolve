#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> map1[10020][10020];   // dis, cost

struct node {
    int curCityId;
    long long curDis;
    long long curCost;
};

pair<long long, long long> res;

void bfs(int N, long long K) {
    queue<node> q;    // curCity, (curDis, curCost)
	bool flag = false;
    q.push({1, 0, 0});
    while (!q.empty()) {
        long long curCity = q.front().curCityId;
        if(curCity == N && q.front().curCost <= K) {
            res = make_pair(q.front().curDis, q.front().curCost);
			return;
		} else if(q.front().curCost > K) {
			q.pop();
			continue;
		}
        for(int i = 1; i <= N; ++i) {
            if(map1[curCity][i].first != 0) {
                long long curDis = q.front().curDis+map1[curCity][i].first, curCost = q.front().curCost+map1[curCity][i].second;
                q.push({i, curDis, curCost});
            }
        }
		q.pop();
    }
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int K, N, R, S, D, L, T;    // K: 花费的最大的金币数, N: 城市的数目, R: 路的数目
    cin >> K >> N >> R;
    for(long long i = 1; i <= R; ++i) {
        cin >> S >> D >> L >> T;
        map1[S][D] = make_pair(L, T);
    }
	bfs(N, K);
}
