#include <bits/stdc++.h>
using namespace std;
char mp1[26] = {
    '2','2','2','3','3','3',
    '4','4','4','5','5','5',
    '6','6','6','7','0','7',
    '7','8','8','8','9','9',
    '9','0'
};

int main() {
	vector<pair<string, int>> v;
	v.reserve(100000);
	unordered_map<string, int> mp;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s1, s2;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
	    cin >> s1;
	    s2.clear();
	    for(long long unsigned int j = 0; j < s1.size(); ++j) {
	        if(s1[j] >= '0' && s1[j] <= '9') {
	            s2.push_back(s1[j]);
	        } else if(s1[j] >= 'A' && s1[j] <= 'Z') {
	            s2.push_back(mp1[s1[j]-'A']);
	        }
	    }
		if(mp.find(s2) != mp.end()) {
			++mp[s2];
		} else {
			mp[s2] = 1;
		}
	}
	for(auto i: mp) {
		if(i.second > 1) {
			string s = i.first;
			s.insert(s.begin()+3, '-');
			v.push_back(make_pair(s, i.second));
		}
	}
	sort(v.begin(), v.end());
	if(v.size() == 0) {
		cout << "No duplicates." << endl;
		return 0;
	}
	for(auto i: v) {
		cout << i.first << " " << i.second << endl;
	}
}
