#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool is1 = false, is2 = false; // is1表示双引号内，is2表示/**/内
    bool is1_ = false, is2_ = false;
    while(cin >> s) {
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '/') {
                if(!is1) is1_ = true;
            } else if(s[i] == '*' && is1_ == true) {
                is1 = true;
                is1_ = false;
            }
        }
    }
}