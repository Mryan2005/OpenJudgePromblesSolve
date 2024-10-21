#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

int a[MAXN][MAXN];

void init(int n) {
    for(int i = 1; i <= n; ++i) a[0][i] = i;
    for(int i = 1; i <= MAXN; ++i) {
        for(int j = 0; j <= n; ++j) a[i][j] = -1;
    }
}

int main() {
    int N, M, t, k, max = 1;
    cin >> N;
    init(N);
    for(int i = 1; i <= N; ++i) {
        cin >> t;
        for(int j = 1; j <= t; ++j) {
            cin >> k;
            max = max > k? max: k;
            a[k][0] = k;
            a[k][i] = 1;
        }
    }
    cin >> M;
    int check[MAXN];
    for(int i = 1; i <= M; ++i) {
        vector<int> res;
        for (int i = 1; i <= N; ++i) cin >> check[i];
        for(int i = 1; i <= max; ++i) {
            int flag = 0;
            if(a[i][0] == -1) continue;
            for(int j = 1; j <= N; ++j) {
                if(check[j] == 0) continue;
                else if(check[j] != a[i][j]) {
                    flag = 1;
                }
            }
            if(flag == 1) {
                flag = 0;
                continue;
            }
            res.push_back(i);
        }
        if(res.size() == 0) {
            cout << "NOT FOUND" << endl;
        } else {
            for(int i = 0; i < res.size(); ++i) {
                if(i == 0) cout << res[i];
                else cout << " " << res[i];
            }
            cout << endl;
        }
    }
}