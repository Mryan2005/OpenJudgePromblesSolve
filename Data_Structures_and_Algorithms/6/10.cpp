#include <bits/stdc++.h>
using namespace std;

long fa[2003], sexRecord[2003], flag;

void initSet(long n) {
    for(long i = 1; i <= n; ++i) {
        fa[i] = i;
        sexRecord[i] = 0;
    }
}

int find(long i) {
    if(fa[i] == i) return i;
    else {
        int end = find(fa[i]);
        sexRecord[i] = sexRecord[i] ^ sexRecord[fa[i]];
        fa[i] = end;
        return fa[i];
    }
}

void union1(long a, long b) {
    int afa = find(a), bfa = find(b);
    if(afa == bfa) {
        if(sexRecord[a] == sexRecord[b]) {
            flag = 1;
            return;
        }
    }
    fa[afa] = bfa;
    sexRecord[afa] = sexRecord[a] ^ sexRecord[b] ^ 1;
}

int main() {
    long t, n, a, b, m;
    scanf("%ld", &t);
    for(long i = 1; i <= t; ++i) {
        scanf("%ld %ld", &n, &m);
        initSet(n);
        flag = 0;
        for(long j = 1; j <= m; ++j) {
            scanf("%ld %ld", &a, &b);
            union1(a, b);
            if(flag) {
                printf("Scenario #%ld:\nSuspicious bugs found!\n\n", i);
                goto out;
            }
        }
        printf("Scenario #%ld:\nNo suspicious bugs found!\n\n", i);
        out:;
    }
}