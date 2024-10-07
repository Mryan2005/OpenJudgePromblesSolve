#include <bits/stdc++.h>
using namespace std;

struct node {
    unordered_map<char, node*> mp;
    int count, isEnd;
} root;

vector<pair<string,string>> res;

void abjust(string s) {
    node *p = &root;
    for(int i = 0; i < s.size(); ++i) {
        if(p->mp.find(s[i]) != p->mp.end()) {
            ++(p->count);
            p = p->mp[s[i]];
        } else {
            p->mp[s[i]] = new node();
            ++(p->count);
            p = p->mp[s[i]];
        }
    }
    p->isEnd = 1;
    p->count += 1;
}

void findShortestPrefixes(string s) {
	node *p = &root;
	int count = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(p->count == 1) {
			res.push_back(make_pair(s, s.substr(0, count)));
			return;
		}
		p = p->mp[s[i]];
		++count;
	}
	res.push_back(make_pair(s, s.substr(0, count)));
}

int main() {
    string s;
	vector<string> v;
    while(cin >> s) {
		v.push_back(s);
    }
	for(auto i: v) {
		abjust(i);
	}
	for(auto i: v) {
		findShortestPrefixes(i);
	}
    for(auto i: res) {
        cout << i.first << " " << i.second << endl;
    }
}
