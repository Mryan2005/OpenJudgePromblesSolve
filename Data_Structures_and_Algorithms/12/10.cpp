#include <bits/stdc++.h>
using namespace std;

void solve() {
	deque<pair<long, long>> q1, q2;
    long o, K, P;
    while(1) {
        scanf("%ld", &o);
        switch (o) {
        case 0:
            return;
        case 1:
            scanf("%ld %ld", &K, &P);
            if(q1.empty()) q1.push_front(make_pair(K, P));
            else {
                while(q1.front().second > P) {
                    q2.push_front(q1.front());
                    q1.pop_front();
                }
                q2.push_front(make_pair(K, P));
                while(!q1.empty()) {
                    q2.push_front(q1.front());
                    q1.pop_front();
                }
                while(!q2.empty()) {
                    q1.push_front(q2.front());
                    q2.pop_front();
                }
            }
            break;
        case 2:
            if(q1.empty()) printf("0\n");
            else {
				printf("%ld\n", q1.front().first);
				q1.pop_front();
			}
            break;
        case 3:
            if(q1.empty()) printf("0\n");
            else {
				printf("%ld\n", q1.back().first);
				q1.pop_back();
			}
            break;
        }
    }
}

int main() {
    solve();
}
