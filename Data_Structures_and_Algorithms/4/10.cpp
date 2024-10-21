#include <bits/stdc++.h>
using namespace std;

int R, C;
char mat[10000][75];
int a[10000];

void countEachLine() {
    int sufferLen;
    for(int i = 0; i < R; ++i) {
        char *s = mat[i];
        for(char *p = s, *q = s+1; *q; ++q) {
            if(*p == *q) {
                sufferLen = q - p;
                ++p;
            } else {
                p = s;
                sufferLen = 0;
            }
        }
        a[i] = sufferLen;
    }
}

int findMin() {
    int min = INT_MAX;
    for(int i = 0; i < R; ++i) {
        min = min > a[i]? a[i]: min;
    }
    return min;
}

int solve() {
    countEachLine();
    return findMin();
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> mat[i][j];
        }
    }
    cout << solve();
}