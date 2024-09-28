#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
array<array<int, 55>, 55> a, b;
int m;

int init() {
    int n, beginIndex, endIndex, dis;
    string t;
    cin >> n;
	m = n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        mp[t] = i;
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> t;
        beginIndex = mp[t];
        cin >> t;
        endIndex = mp[t];
        cin >> dis;
        a[beginIndex][endIndex] = dis;
        a[endIndex][beginIndex] = dis;
    }
}

int find() {
    int n, bp, epL, minDis = INT_MAX, endPlace;
    string beginP, endP;
    pair<int, int> temp;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> beginP >> endP;
        if(mp[beginP] == mp[endP]) {
            cout << beginP << endl;
            return 0;
        }
        endPlace = mp[endP], bp = mp[beginP];
        queue<pair<int, int>> Q;   // save next place and sum dis
        for(int j = 0; j < m ; ++j) {
            if(a[mp[beginP]][j] != 0) {
                Q.push({j, a[mp[beginP]][j]});
				b[j][mp[beginP]] = 1;
            }
        }
        while(!Q.empty()) {
            epL = bp;
            // bp =
            temp = Q.front();
            bp = temp.first;
            Q.pop();
            if(bp == endPlace) minDis = minDis > temp.second? temp.second: minDis;
            for(int j = 0; j < m; ++j) {
                if(a[bp][j] != 0 && b[bp][j] == 0) {
                    Q.push({j, temp.second+a[bp][j]});
					b[j][bp] = 1;
                }
            }
        }
		return minDis;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    find();
}
