#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;

int main() {
    int N, M, t, k;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> t;
        for(int j = 1; j <= t; ++j) {
            cin >> k;
            mp[i].push_back(k);
        }
        sort(mp[i].begin(), mp[i].end());
    }
    cin >> M;
    for(int i = 1; i <= M; ++i) {
        vector<int> res, temp;
        for(int j = 1; j <= N; ++j) {
            cin >> k;
            switch (k) {
            case 1:
                if(j == 1) {
                    for(auto t: mp[j]) {
                        res.push_back(t);
                    }
                } else {
                    for(auto t: mp[j]) {
                        for(int l = 0; l < res.size(); ++l) {
                            if(t == res[l]) {
                                temp.push_back(t);
                                break;
                            }
                        }
                    }
                    res.clear();
                    for(auto l: temp) {
                        res.push_back(l);
                    }
                    temp.clear();
                }
                break;
            case 0:
                break;
            case -1:
                if(j == 1) {
                    break;
                }
                for(int k = 0; k < mp[j].size(); ++k) {
                    for(int l = 0; l < res.size(); ++l) {
                        if(mp[j][k] == res[l]) {
                            res.erase(res.begin()+l, res.begin()+l+1);
                            break;
                        }
                    }
                }
                break;
            }
        }
        if(res.size() == 0) {
            cout << "NOT FOUND" << endl;
        } else {
            int h = 1;
            for(auto j: res) {
                if(h == 1) cout << j;
                else cout << " " << j ;
                ++h;
            }
            cout << endl;
        }
    }
}