#include <bits/stdc++.h>
using namespace std;
char *s = (char*)malloc(sizeof(char)*10000006);

int main() {
    while(scanf("%s", s) && s[0] != '.') {
        int res = 0, loop = 1;
        for(int i = 0, j = 1; j < strlen(s); ++j) {
            if(s[i] == s[j]) {
                res++;
                ++i;
            } else {
                ++loop;
            }
        }
        printf("%d\n", res/loop+1);
    }
}