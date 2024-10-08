#include <bits/stdc++.h>
using namespace std;

int reres;
unordered_map<char, int> mp1;
int map_[26][26], weight[26], parent[26], minDis = INT_MAX, minid;
char wl[26];
bool isSelect[26];

void initMap_() {
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
            map_[i][j] = INT_MAX;
        }
    }
}

void initwl() {
    for(int i = 0; i < 26; ++i) {
        wl[i] = 'A'+i;
        mp1['A'+i] = i;
        weight[i] = INT_MAX;
        isSelect[i] = false;
    }
}

int findMin() {
    int res = INT_MAX, id;
    for(int i = 0; i < 26; ++i) {
        if(isSelect[i] == false && res > weight[i]) {
            res = weight[i];
            id = i;
        }
    }
    return id;
}

void add(int nodeId) {
    isSelect[nodeId] = true;
    reres += weight[nodeId];
    for(int i = 0; i < 26; ++i) {
        if(weight[i] > map_[nodeId][i] && isSelect[i] == false) {
            weight[i] = map_[nodeId][i];
            parent[i] = nodeId;
        }
    }
}

void solve(int n) {
    parent[minid] = -1;
    weight[minid] = 0;
    int nimId = minid;
    while(n--) {
        add(nimId);
        nimId = findMin();
    }
}

void inputData(int n) {
    int m, c;
    char w, d;
    for(int i = 0; i < n-1; ++i) {
        cin >> w >> m;
        for(int j = 1; j <= m; ++j) {
            cin >> d >> c;
            map_[w-'A'][d-'A'] = c;
            map_[d-'A'][w-'A'] = c;
            if(minDis > c) {
                minDis = c;
                minid = w-'A';
            }
        }
    }
}

int main() {
    int n;
    initwl();
    initMap_();
    scanf("%d", &n);
    inputData(n);
    solve(n);
    printf("%d", reres);
}