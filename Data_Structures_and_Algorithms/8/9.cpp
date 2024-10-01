#include <bits/stdc++.h>
using namespace std;

array<pair<int,int>, 10000> a1;
unordered_map<int, int> mp;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

int main() {
    int N, a, b, canSlect = 0, sum = 0;
    scanf("%d", &N);
    canSlect = N;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &a, &b);
        a1[i].first = a;
        a1[i].second = b;
    }
    sort(a1.begin(), a1.begin()+N, cmp);
    for(int i = 0; i < N; ++i) {
        int j = a1[i].second;
        while(j > 0 && mp.find(j) != mp.end()) {
            --j;
        }
        if(j != 0) {
            mp[j] = a1[i].first;
            sum += a1[i].first;
        }
    }
    printf("%d", sum);
}