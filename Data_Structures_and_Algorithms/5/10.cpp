#include <bits/stdc++.h>
using namespace std;

int a[101][2] = {};    /* ChildL, ChildR */

void createTree(int n) {
    int index, ChildL, ChildR;
    for(int i = 1; i <= n; ++i) {
        cin >> index >> ChildL >> ChildR;
        a[index][0] = ChildL;
        a[index][1] = ChildR;
    }
}

void swap(int x, int y, int n) {
    pair<int, bool> pX, pY;     // indexId, l(0), r(1)
    for(int i = 0; i < n ; ++i) {
        if(x == a[i][0]) {
            pX.first = i;
            pX.second = 0;
            break;
        } else if(x == a[i][1]) {
            pX.first = i;
            pX.second = 1;
            break;
        }
    }
    for(int i = 0; i < n ; ++i) {
        if(y == a[i][0]) {
            pY.first = i;
            pY.second = 0;
            break;
        } else if(y == a[i][1]) {
            pY.first = i;
            pY.second = 1;
            break;
        }
    }
    if(pX.second == 0) {
        a[pX.first][0] = y;
    } else {
        a[pX.first][1] = y;
    }
    if(pY.second == 0) {
        a[pY.first][0] = x;
    } else {
        a[pY.first][1] = x;
    }
}

void findLeftestChildAndPrint(int beginP) {
    while(a[beginP][0] != -1) {
        beginP = a[beginP][0];
    }
    cout << beginP << endl;
}

int main() {
    int t, n, m, typ, x, y;
    scanf("%d", &t);
    for(int i = 1;i <= t; ++i) {
        scanf("%d %d", &n, &m);
        createTree(n);
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &typ);
            if(typ == 1) {
                scanf("%d %d", &x, &y);
                swap(x, y, n);
            } else {
                scanf("%d", &x);
                findLeftestChildAndPrint(x);
            }
            
        }
    }
}
