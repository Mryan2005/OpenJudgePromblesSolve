#include <bits/stdc++.h>
using namespace std;

array<vector<int>, 100004> map_;
queue<pair<int, int>> q;
bool visited[100004];

int init(int n) {
    for(auto i: map_) {
        i.clear();
    }
    for(int i = 0; i <= n; ++i) {
        visited[i] = false;
    }
}

void bfs()

int main() {
    int N, M, T, x, y;
    bool flag = false;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cin >> N >> M;
        init(N);
        for(int j = 1; j <= M; ++j) {
            cin >> x >> y;
            map_[x].push_back(y);
        }
        for(int j = 1; j <= N; ++j) {
            if()
        }
        if(flag) cout << "Yes" << endl;
        else cout << "NO" << endl;
        flag = false;
    }
}