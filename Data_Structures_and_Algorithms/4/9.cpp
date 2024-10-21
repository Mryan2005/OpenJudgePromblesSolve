#include <bits/stdc++.h>
using namespace std;

vector<int> ar;
string b;

void kmpInit() {
    ar.clear();
    ar.push_back(0);
    for(int i = 0, j = 1; j < b.size();) {
        if(b[i] == b[j]) {
            ++i;
            ar.push_back(i);
            ++j;
        } else {
            if(i != 0) {
                i = ar[i-1];
            } else {
                ar.push_back(i);
                ++j;
            }
        }
    }
}

int main() {
    int n;
    int T = 1;
    while(cin >> n, n) {
        cin >> b;
        kmpInit();
        cout << "Test case #" << T++ << endl;
        for(int i = 2; i <= n; ++i) {
            int t = i - ar[i-1];
            if(i != t && i % t == 0) {
                cout << i << " " << i/t << endl;
            }
        }
        cout << endl;
    }
}