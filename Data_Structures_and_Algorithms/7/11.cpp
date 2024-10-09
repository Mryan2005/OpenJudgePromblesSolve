#include <bits/stdc++.h>
using namespace std;
#define MAXN 300

int reres, count1 = 0;
int map_[MAXN][MAXN], weight[MAXN], parent[MAXN];
bool isSelect[MAXN];
int nimId = 1;

void initMap_() {
    for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < MAXN; ++j) {
            map_[i][j] = INT_MAX;
        }
    }
}

void initwl() {
    for(int i = 0; i < MAXN; ++i) {
        weight[i] = INT_MAX;
        isSelect[i] = false;
    }
}

int findMin(int n) {
    int res = INT_MAX, id;
    for(int i = 1; i <= n; ++i) {
        if(isSelect[i] == false && res > weight[i]) {
            res = weight[i];
            id = i;
        }
    }
    return id;
}

void add(int nodeId, int n) {
    isSelect[nodeId] = true;
    reres += weight[nodeId];
    for(int i = 1; i <= n; ++i) {
        if(weight[i] > map_[nodeId][i] && isSelect[i] == false) {
            weight[i] = map_[nodeId][i];
            parent[i] = nodeId;
        }
    }
}

void solve(int n) {
    parent[nimId] = -1;
    weight[nimId] = 0;
    int k = n;
    while(n--) {
        add(nimId, k);
        nimId = findMin(k);
        for(int i = 1; i <= k; ++i) {
            if(weight[i] == weight[nimId] && i != nimId && nimId <= MAXN) ++count1;
        }
    }
}

void inputData(int m) {
    int xi, yi, wi;
    for(int i = 1; i <= m; ++i) {
        cin >> xi >> yi >> wi;
        map_[yi][xi] = wi;
        map_[xi][yi] = wi;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int n, m;
        cin >> n >> m;
        reres = 0;
        count1 = 0;
        initwl();
        initMap_();
        inputData(m);
        solve(n);
        if(count1 < 1) printf("%d\n", reres);
        else printf("Not Unique!\n");
    }
}