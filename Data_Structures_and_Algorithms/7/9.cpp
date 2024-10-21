#include <bits/stdc++.h>
using namespace std;

int mp[1000][1000];
int nodeParent[1000];

void initNodeList(int n) {
    for(int i = 1; i <= n+1; ++i) {
        nodeParent[i] = i;
    }
}

int findParent(int i) {
    if(i == nodeParent[i]) return i;
	else {
	    nodeParent[i] = findParent(nodeParent[i]);
	    return nodeParent[i];
	}
}

void union1(int a, int b) {
    int p1 = findParent(a), p2 = findParent(b);
	if(p2 == b) nodeParent[p2] = p1;
	else nodeParent[p1] = p2;
}

int main() {
    int N;
    string s;
    cin >> N;
	initNodeList(N);
    for(int i = 1; i <= N; ++i) {
        cin >> s;
        for(long long unsigned int j = 0; j < s.size(); ++j) {
            mp[i][j+1] = s[j] - '0';
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(mp[i][j] == 1) {
                union1(i, j);
            }
        }
    }
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			if(nodeParent[i] == nodeParent[j]) {
				mp[i][j] = mp[j][i] = 1;
			}
		}
	}
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cout << mp[i][j];
        }
        cout << endl;
    }
}
