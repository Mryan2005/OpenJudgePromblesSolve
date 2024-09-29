#include <bits/stdc++.h>
using namespace std;

struct node {
    char data[100];
    node *l, *r;
};

node *initTree() {
    return NULL;
}

vector<string> processInput(string path) {
    string cur;
    vector<string> res;
    int i = 0, j = 0;
    for(; i < path.size(); ++i) {
        if(path[i] == '\\') {
            cur = path.substr(j, i-j);
            res.insert(res.end(), cur);
            j = i+1;
        }
    }
    cur = path.substr(j, i-j);
    res.insert(res.end(), cur);
    return res;
}

void addNode(node **T, vector<string> res) {
    node *p = *T;
    for(int i = 0; i < res.size(); ++i) {
        if(p == NULL) {
            if(i == 0) {
                *T = (node*)malloc(sizeof(node));
                strcpy((*T)->data, res[i].c_str());
                (*T)->l = (*T)->r = NULL;
				p = *T;
            }
        } else if(p && p->l == NULL) {
            p->l = (node*)malloc(sizeof(node));
            p = p->l;
            strcpy(p->data, res[i].c_str());
            p->l = p->r = NULL;
        } else {
            while(1) {
                if(strcmp(res[i].c_str(), p->data) > 0) {
                    p = p->r;
                } else if(strcmp(res[i].c_str(), p->data) == 0) {
                    if(p->l) p = p->l;
					else break;
                } else if(strcmp(res[i].c_str(), p->data) < 0) {
                    node *q = (node*)malloc(sizeof(node));
                    strcpy(q->data, res[i].c_str());
                    q->l = q->r = NULL;
					if(p == *T) {
						q->r = (*T);
						*T = q;
						p = (*T);
					} else {
	                    q->r = p;
	                    p->r = q;
	                    p = q;
					}
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string path;
    node *T;
    cin >> n;
    T = initTree();
    for(int i = 1; i <= n; ++i) {
        cin >> path;
        vector<string> res = processInput(path);
        addNode(&T, res);
    }
    // printDir();
}
