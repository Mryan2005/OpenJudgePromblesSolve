#include <bits/stdc++.h>
using namespace std;
int mp1[24];
unordered_map<string, int> mp;

void initMP1() {
    for(int i = 0, k = 2; i < 24; i += 3) {
        for(int j = i; j < i+3; ++j) {
            mp1[j] = k;
        }
        ++k;
    }
}

int main() {
    int n;
    initMP1();
    scanf("%d", &n)
}