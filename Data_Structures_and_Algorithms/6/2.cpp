#include <bits/stdc++.h>
using namespace std;

struct node {
    char data;
    node *l, *r;
};

node *initTree() {
    return NULL;
}


void createATree(node **T, string s, int i) {

    createATree(&(*T)->l, s, i);
}

int main() {
    node *T = initTree();

}