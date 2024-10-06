#include <bits/stdc++.h>
using namespace std;

pair<long, long> map1[10003][10003];   // dis, cost
int re[10003][10003];

struct node {
    long curDis;
    long curCost;
};

bool record[10003], isfind;

node res = {LONG_MAX, LONG_MAX}, cur;

void dfs(int curId, int N, int K) {
    if(curId == N) {
        if(cur.curDis < res.curDis) {
            res.curCost = cur.curCost;
            res.curDis = cur.curDis;
            isfind = true;
        }
        return;
    }
    for(int i = 1; i <= N; ++i) {
        if(map1[curId][i].first != 0 && record[i] == false) {
            if(cur.curCost + map1[curId][i].second > K) continue;
            if(cur.curDis + map1[curId][i].first > res.curDis+20) continue;
            cur.curDis += map1[curId][i].first;
            cur.curCost += map1[curId][i].second;
            record[curId] = true;
            re[curId][i] = cur.curDis;
            dfs(i, N, K);
            record[curId] = false;
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
    for(long i = 1; i <= R; ++i) {
        cin >> S >> D >> L >> T;
        if(S != D) map1[S][D] = make_pair(L, T);
    }
    cur = {0, 0};
    record[1] = true;
	dfs(1, N, K);
    if(isfind) cout << res.curDis<<endl;
    else cout << "-1"<<endl;
}
