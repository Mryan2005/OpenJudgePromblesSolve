#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

int tree[MAXN][MAXN], res, minbegin = INT_MAX;
bool isGo[MAXN];

struct node {
    int u, v, SumW;
};

// void bfs(int n) {
//     queue<node> q;
//     q.push({tree[minbegin][0], tree[minbegin][1], tree[minbegin][2]});
//     while(!q.empty()) {
//         node cur = q.front();
//
// 		q.pop();
//     }
// }

void initA() {
    for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < MAXN; ++j) {
            tree[i][j] = INT_MAX;
        }
    }
}

void dfs(node cur, int n) {
    res = res < cur.SumW? cur.SumW: res;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(isGo[j]) continue;
            if(tree[i][j] == INT_MAX) continue;
            if(cur.SumW^tree[i][2] > res) {
                isGo[i] = true;
                dfs({tree[i][0], tree[i][1], cur.SumW^tree[i][2]}, n);
                isGo[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    initA();
    for(int i = 0; i < n-1; ++i) {
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
        minbegin = minbegin > tree[i][0]? tree[i][0]: minbegin;
    }
    dfs({tree[minbegin][0], tree[minbegin][1], tree[minbegin][2]}, n);
	cout << res;
}
