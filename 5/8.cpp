#include <bits/stdc++.h>
using namespace std;

struct BiTNode {
	char data;
	BiTNode *left, *right;
};

void usingPreorderTListAndInorderTListCreateTree(BiTNode **Node, string pTList, string iTList, int *i, int begin, int end) {
	if(*Node == NULL) {
		int mid = -1;
		for(int j = begin; j < end; j++) {
			if(pTList[*i] == iTList[j]) {
				mid = j;
				break;
			}
		}
		if(mid == -1) return;
		*Node = (BiTNode*)malloc(sizeof(BiTNode));
		(*Node)->data = pTList[*i];
		(*Node)->left = (*Node)->right = NULL;
		(*i)++;
		usingPreorderTListAndInorderTListCreateTree(&((*Node)->left), pTList, iTList, i, begin, mid);
		usingPreorderTListAndInorderTListCreateTree(&((*Node)->right), pTList, iTList, i, mid+1, end);
	}
} 

void f(BiTNode *T) {
	if(T) {
		f(T->left);
		f(T->right);
		printf("%c", T->data);
	}
}


int main() {
	string s1, s2;
	while(cin >> s1 >> s2) {
		BiTNode *T = NULL;
		int i = 0;
		usingPreorderTListAndInorderTListCreateTree(&T, s1, s2, &i, 0, s1.size());
		f(T);
		printf("\n");
	}
}