#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> map1[10020][10020];   // dis, cost

struct node {
    long long curDis;
    long long curCost;
};

node res = {LONG_MAX, LONG_MAX}, cur;

void dfs(int curId, int N, int K) {
    if(cur.curCost > K) return;
    if(curId == N) {
        if(cur.curCost <= K && cur.curDis < res.curDis) {
            res.curCost = cur.curCost;
            res.curDis = cur.curDis;
        }
        return;
    }
    for(int i = 1; i <= N; ++i) {
        if(map1[curId][i].first != 0) {
            cur.curDis += map1[curId][i].first;
            cur.curCost += map1[curId][i].second;
            dfs(i, N, K);
            cur.curDis -= map1[curId][i].first;
            cur.curCost -= map1[curId][i].second;
        }
    }
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
    cur = {0, 0};
	dfs(1, N, K);
    cout << res.curDis;
}
