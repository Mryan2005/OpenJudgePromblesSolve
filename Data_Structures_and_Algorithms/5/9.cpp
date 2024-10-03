#include <bits/stdc++.h>
using namespace std;
long countL, countR, a1, b1;

void solve(long a, long b) {
    countL = countR = 0;
    a1 = a;
    b1 = b;
    while(a1 != 1 || b1 != 1) {
        if(a1 > b1) {
            countL += a1/b1;
            if(a1 % b1 == 0) {
                --countL;
                a1 = 1;
            } else {
                a1 = a1 % b1;
            }
        } else {
            countR += b1 / a1;
            if(b1 % a1 == 0) {
                --countR;
                b1 = 1;
            } else {
                b1 = b1 % a1;
            }
        }
    }
}

int main() {
    long N, a, b;
    scanf("%ld", &N);
    for(long i = 1; i <= N; ++i) {
        scanf("%ld %ld", &a, &b);
        solve(a, b);
        printf("Scenario #%ld:\n%ld %ld\n\n", i, countL, countR);
    }
}
