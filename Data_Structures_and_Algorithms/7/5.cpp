#include <bits/stdc++.h>
using namespace std;
int ar[1024][1024];
int f[1024];
bool isSelect[1024];
vector<int> res;

void process(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(ar[i][j] == 1) {
                ++f[j];
            }
        }
    }
}

int select(int n) {
    for(int i = 1; i <= n; ++i) {
        if(f[i] == 0 && isSelect[i] != true) {
            isSelect[i] = true;
            return i;
        }
    }
}

void remove(int id, int n) {
    for(int i = 1; i <= n; ++i) {
        if(ar[id][i] == 1) {
            --f[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v, a, b, c, n;
    cin >> v >> a;
    n = v;
    res.reserve(n);
    for(int i = 1; i <= a; ++i) {
        cin >> b >> c;
        ar[b][c] = 1;
    }
    process(v);
    while(n--) {
        int id = select(v);
        remove(id, v);
        res.push_back(id);
    }
    for(auto i: res) cout << "v" << i << " ";
}
