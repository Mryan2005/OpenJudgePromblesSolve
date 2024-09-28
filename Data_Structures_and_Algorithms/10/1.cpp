#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    v.reserve(10000);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t;
    unordered_map<string, bool> mp;
    while(cin >> s && s[0] != '#') {
        mp[s] = 1;
    }
    while(cin >> s && s[0] != '#') {
        if(mp.count(s) != 0) {
            cout << s << " is correct" << endl;
            continue;
        } else {
            for(int i = 0; i < t.size(); ++i, t = s) {
                t.erase(i, 1);
                for(auto i: mp) {
                    if(i.first.find(t)) v.insert(v.end(), i.first);
                }
            }
            for(int i = 0; i < t.size(); ++i, t = s) {
                t.erase(i, 1);
                for(auto i: mp) {
                    if(i.first.find(t)) v.insert(v.end(), i.first);
                }
            }
        }
    }
}