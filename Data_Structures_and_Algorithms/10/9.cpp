#include <bits/stdc++.h>
using namespace std;
long N, a[90020], b[90020];

void solve() {
    stack<long> S;   // save index
    for(int i = 0; i < N; ++i) {
        while(!S.empty() && a[S.top()] <= a[i]) {
            S.pop();
        }
        if(!S.empty()) b[i] = S.size();
        S.push(i);
    }
    long sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += b[i];
    }
    cout << sum;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    solve();
}