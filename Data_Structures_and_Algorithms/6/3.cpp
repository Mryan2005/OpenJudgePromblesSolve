#include <bits/stdc++.h>
using namespace std;

struct node {
    map<string, node*> mp;
} root;

void solve(string s) {
    string subS;
    node *p = &root;
    int j = 0, k = j;
    for(; j < s.size(); ++j) {
        if(s[j] == '\\') {
            subS = s.substr(k, j-k);
            if(p->mp.find(subS) == p->mp.end()) {
                p->mp[subS] = new node;
                p = p->mp[subS];
            } else {
                p = p->mp[subS];
            }
			k = j+1;
        }
    }
    subS = s.substr(k, j-k);
    if(p->mp.find(subS) == p->mp.end()) {
        p->mp[subS] = new node;
        p = p->mp[subS];
    } else {
        p = p->mp[subS];
    }
}

void outputRes(node *curP, int f) {
	for(auto i: curP->mp) {
		for(int i = 1; i <= f; ++i) {
			cout << " ";
		}
		cout << i.first << endl;
		outputRes(i.second, f+1);
	}
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        string s, subS;
        cin >> s;
        solve(s);
    }
	outputRes(&root, 0);
}
