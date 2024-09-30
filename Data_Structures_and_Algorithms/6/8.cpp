#include <bits/stdc++.h>
using namespace std;

int fa[50010], res;

void initSet(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int find(int i) {
    if(i == fa[i]) {
        return i;
    } else {
        fa[i] = find(fa[i]);
        return fa[i];
    }
}

void union1(int a, int b) {
    int afa = find(a), bfa = find(b);
    fa[bfa] = afa;
    if(bfa != afa) --res;
}

int getRes(int n) {
    set<int> se;
    for(int i = 1; i <= n; ++i) {
        se.insert(se.end(), fa[i]);
    }
    return se.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, j , k, l = 1;
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        initSet(n);
        res = n;
        for(int i = 1; i <= m; ++i) {
            cin >> j >> k;
            union1(j, k);
        }
        cout << "Case " << l << ": " << res << endl;
        ++l;
    }
}