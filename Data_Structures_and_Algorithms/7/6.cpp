#include <bits/stdc++.h>
using namespace std;

double reres;
unordered_map<char, int> mp1;
double map_[103][103], weight[103];
int parent[103], map_1[103][2];
char wl[103];
bool isSelect[103];

void initMap_() {
    for(int i = 0; i <= 100; ++i) {
        for(int j = 0; j <= 100; ++j) {
            map_[i][j] = INT_MAX;
        }
    }
}

void initwl() {
    for(int i = 0; i <= 100; ++i) {
        wl[i] = i;
        mp1[i] = i;
        weight[i] = INT_MAX;
        isSelect[i] = false;
    }
}

int findMin() {
    int res = INT_MAX, id;
    for(int i = 0; i <= 100; ++i) {
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
    for(int i = 0; i <= 100; ++i) {
        if(weight[i] > map_[nodeId][i] && isSelect[i] == false) {
            weight[i] = map_[nodeId][i];
            parent[i] = nodeId;
        }
    }
}

void solve(int n) {
    parent[1] = -1;
    weight[1] = 0;
    int nimId = 1;
    while(n--) {
        add(nimId);
        nimId = findMin();
    }
}

void inputData(int m) {
    int b, e;
    for(int i = 1; i <= m; ++i) {
        cin >> b >> e;
        if(b != e) map_[b][e] = sqrt((map_1[b][0]-map_1[e][0])*(map_1[b][0]-map_1[e][0]) + (map_1[b][1]-map_1[e][1])*(map_1[b][1]-map_1[e][1]));
    }
}

void inputDis(int n) {
    for(int i = 0; i <= n; ++i) {
        cin >> map_1[i][0] >> map_1[i][1];
    }
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        reres = 0;
        initwl();
        initMap_();
        inputDis(n);
        inputData(m);
        solve(n);
        printf("%0.2lf\n", reres);
    }
}