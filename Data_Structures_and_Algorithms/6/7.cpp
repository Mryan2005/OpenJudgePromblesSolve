#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *l, *r;
};

void createATree(node **TF, node **T, string s, int *ind) {
    *T = (node*)malloc(sizeof(node));
    (*T)->data = *ind;
    if(s[*ind] == 'd') {
        *ind += 1;
        createATree(T, &((*T)->l), s, ind);
    } else {
        *ind += 1;
        createATree(TF, &((*TF)->r), s, ind);
    }
}

int main() {
    string s;
    int i = 0;
    node *T;
    getline(cin, s);
    createATree(&T, &T, s, &i);
}