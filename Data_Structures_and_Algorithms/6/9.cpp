#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 10

struct node {
    struct node *CL[MAXSIZE];
    int isFinal;
    int count;
};
node root;
int t, n;
int flag;
void initTree(node *a) {
    for(int i = 0; i < MAXSIZE; ++i) a->CL[i] = NULL;
    a->count = 0;
    a->isFinal = 0;
}

void createATree(node *r, string s) {
    node *p = r;
    for(int i = 0; i < s.size(); ++i) {
        if(p->CL[s[i] - '0'] == NULL) {
            p->CL[s[i] - '0'] = new node();
            initTree(p->CL[s[i] - '0']);
        }
        p = p->CL[s[i] - '0'];
        if(p->isFinal) {flag = 0;}
        p->count++;
    }
    if(p->count > 1) {flag = 0;}
    p->isFinal = 1;
}

void clear(node *r) {
    for (int i = 0; i < 10; i++) {
        if (r->CL[i]) { clear(r->CL[i]); }
    }
    if(r != &root) free(r);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string ss;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        initTree(&root);
        flag = 1;
        cin >> n;
        for(int j = 1; j <= n; ++j) {
            cin >> ss;
            if(flag) {createATree(&root, ss);}
        }
        if(flag == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
        clear(&root);
    }
    return 0;
}