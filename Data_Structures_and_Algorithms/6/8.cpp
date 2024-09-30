#include <bits/stdc++.h>
using namespace std;

int fa[50010], res;

int find(int i) {
    if(i == fa[i]) return i;
    else {
        fa[i] = find(fa[i]);
        return fa[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, j , k, l = 1;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        res = n;
        for(int i = 1; i <= m; ++i) {
            cin >> j >> k;
            int afa = find(j), bfa = find(k); fa[bfa] = afa;
            if(bfa != afa) --res;
        }
        cout << "Case " << l << ": " << res << endl;
        ++l;
    }
}