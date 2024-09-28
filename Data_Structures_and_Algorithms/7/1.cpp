#include <bits/stdc++.h>
#define N 100
using namespace std;
unordered_map<string, int> mp;
array<string, N+1> mp1;
array<array<int, N+1>, N+1> place;
array<pair<int, int>, N+1> a;
array<bool, N+1> b;
int m;

void init() {
    int n, beginIndex, endIndex, dis;
    string t;
    cin >> n;
	m = n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        mp[t] = i;
		mp1[i] = t;
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> t;
        beginIndex = mp[t];
        cin >> t;
        endIndex = mp[t];
        cin >> dis;
        place[beginIndex][endIndex] = dis;
        place[endIndex][beginIndex] = dis;
    }
}

void initList(int beginP, int n) {
    a[beginP].first = 0;
    b[beginP] = false;
    a[beginP].second = -1;
    for(int i = 0; i < n; ++i) {
        if(i == beginP) continue;
        a[i].first = INT_MAX;
        a[i].second = -1;
        b[i] = false;
    }
}


void findAndUpdate(int n, int endP) {
    int minInd, minDis = INT_MAX , count = 0;
	while(1) {
		minDis = INT_MAX;
		for(int i = 0; i < n; ++i) {
	        if(minDis > a[i].first && b[i] != 1) {
	            minDis = a[i].first;
	            minInd = i;
	        }
	    }
	    b[minInd] = 1;
		if(minInd == endP) break;
	    for(int i = 0; i < n; ++i) {
	        if(b[i] == 0 && place[minInd][i] != 0) {
	            if(place[minInd][i]+minDis < a[i].first) {
	                a[i].first = place[minInd][i]+minDis;
	                a[i].second = minInd;
	            }
	        }
	    }
	}
}

vector<int> getRoad(int n, int endP) {
	vector<int> v;
	for(int p = endP; p != -1; ) {
		v.insert(v.begin(), p);
		p = a[p].second;
	}
	return v;
}

void printRoad(vector<int> v) {
	int i = 0, j = 1;
	for(; j < v.size(); ++j, ++i) {
		if(i == 0) {
			cout << mp1[v[i]] << "->(" << place[v[j]][v[i]] << ")";
		} else {
			cout << "->" << mp1[v[i]] << "->(" << place[v[j]][v[i]] << ")";
		}
	}
	if(i != 0) cout << "->" << mp1[v[i]] << endl;
	else cout << mp1[v[i]] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string s, s1;
    init();
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s >> s1;
        initList(mp[s], m);
        findAndUpdate(m, mp[s1]);
		vector<int> res = getRoad(m, mp[s1]);
		printRoad(res);
    }
}
