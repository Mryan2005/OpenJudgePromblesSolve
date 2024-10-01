#include <bits/stdc++.h>
using namespace std;
#define nonRelate 0

int res = 0;

struct obj {
    int fa;
    int relationship;   // 0: initial, 1: be eaten, 2: eat, 3: same type
} objs[50030];

void initSet(int n) {
    for(int i = 1; i <= n; ++i) {
        objs[i].fa = i;
        objs[i].relationship = 0;
    }
}

int findFa(int a) {
    if(objs[a].fa == a) return a;
    else {
        return objs[a].fa = findFa(objs[a].fa);
    }
}

// int findSameType(int a) {
//     if(sameType[a] == a) return a;
//     else {
//         sameType[a] = findSameType(sameType[a]);
//         return sameType[a];
//     }
// }

void getRes(int D, int x, int y) {
    int xfa = findFa(x), yfa = findFa(y);
    if(D == 1) {
        if(xfa != x || yfa != y) {
            res++;
        } else {
            sameType[xSameType] = ySameType;
        }
    } else {
        if(sameType[xSameType] == sameType[ySameType]) {
            res++;
        } else {
            fa[xfa] = yfa;
        }
    }
}

int main() {
    int N, K, D, X, Y;
    scanf("%d %d", &N, &K);
    initSet(N);
    for(int i = 1; i <= K; ++i) {
        scanf("%d %d %d", &D, &X, &Y);
        if(X > N || Y > N) {
            res++;
            continue;
        } else if(D == 2 && X == Y) {
            res++;
            continue;
        } else {
            getRes(D, X, Y);
        }
    }
    printf("%d", res);
}