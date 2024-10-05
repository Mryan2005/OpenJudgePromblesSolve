#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

int ar[1024], in[1024];

void reflushHeap(int n) {
	int i = 1;
	int tem;
	while(2*i <= n || 2*i+1 <= n) {
		if(2*i <= n && 2*i+1 <= n) {
			if(ar[2*i] < ar[2*i+1]) {
				if(ar[i] > ar[2*i]) {
					tem = ar[i];
					ar[i] = ar[2*i];
					ar[2*i] = tem;
					i = 2*i;
				}
			} else {
				if(ar[i] > ar[2*i+1]) {
					tem = ar[i];
					ar[i] = ar[2*i+1];
					ar[2*i+1] = tem;
					i = 2*i+1;
				}
			}
		} else if(2*i <= n && 2*i+1 > n) {
			if(ar[i] > ar[2*i]) {
				tem = ar[i];
				ar[i] = ar[2*i];
				ar[2*i] = tem;
				i = 2*i;
			}
		} else break;
	}
}

int main() {
	vector<int> res;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m, n, t, j = 1, tem;
	cin >> m >> n;
	res.reserve(m);
	for(int i = 1; i <= m; ++i) {
		cin >> in[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	t = m;
	while(t--) {
		if(n <= 0) break;
		res.push_back(ar[1]);
		if(res.back() > in[j]) {
			ar[1] = in[j];
			tem = ar[1];
			ar[1] = ar[n];
			ar[n] = tem;
			--n;
			reflushHeap(n);
		} else {
			ar[1] = in[j];
			reflushHeap(n);
		}
		++j;
	}
	for(auto i: res) {
		cout << i << " ";
	}
}