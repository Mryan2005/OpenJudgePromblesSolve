#include <bits/stdc++.h>
using namespace std;

int a[1024];
deque<int> res;
/*
 * input: begin1, end1, vector, &winner
 * return: winner
 */

int createLoserTree(int begin, int end) {
    if(begin >= end) return begin;
    else {
        int winner1 = createLoserTree(begin, (begin+end)/2);
        int winner2 = createLoserTree((begin+end)/2, end-1);
        if(a[winner1] > a[winner2]) {
            res.push_front(winner1);
            return winner2;
        } else {
            res.push_front(winner2);
            return winner1;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
	cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    createLoserTree(0, n);
}
