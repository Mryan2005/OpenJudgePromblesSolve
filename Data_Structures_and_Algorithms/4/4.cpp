#include <bits/stdc++.h>
using namespace std;
char *s = (char*)malloc(sizeof(char)*10000006);

int main() {
    while(scanf("%s", s) && s[0] != '.') {
        int res, sufferLen = 0;
        if(strlen(s) % 2 == 0) {
            for(char *p = s, *q = s+1; *q; ++q) {
                if(*p == *q) {
                    sufferLen = q - p;
                    ++p;
                } else {
                    p = s;
                    sufferLen = 0;
                }
            }
            if(sufferLen == 0) sufferLen = strlen(s);
            res = strlen(s)/sufferLen;
            if(strlen(s) % sufferLen == 0) cout << res << endl;
            else cout << "1" << endl;
        } else cout << "1" << endl;
    }
}