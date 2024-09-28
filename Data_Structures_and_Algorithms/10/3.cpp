#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T, N, M, a, b;
    char typ;
    unordered_map<int, vector<int>> mp;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cin >> N >> M;
        for(int k = 1; k <= M; ++k) {
            cin >> typ >> a >> b;
            if(typ == 'A') {
                if(mp.count(a) == 0) cout << "Not sure yet." << endl;
                if(mp.count(a) != 0) {
                    for(auto j: mp[a]) {
                        if(j == b) {
                            cout << "In different gangs." << endl;
                            goto out;
                        }
                    }
                    cout << "In the same gang." << endl;
                }
            } else {
                mp[a].push_back(b);
                mp[b].push_back(a);
            }
            out:;
        }
    }
}