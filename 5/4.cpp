#include <bits/stdc++.h>
using namespace std;

struct BiTNode {
	int data;
	BiTNode *left, *right;
};

void usingInorderTListAndPostorderTListCreateTree(BiTNode **Node, int *pTList, int *iTList, int *i, int begin, int end) {
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
		(*i)--;
		usingInorderTListAndPostorderTListCreateTree(&((*Node)->right), pTList, iTList, i, mid+1, end);
		usingInorderTListAndPostorderTListCreateTree(&((*Node)->left), pTList, iTList, i, begin, mid);
	}
} 

void f(BiTNode *T) {
	if(T) {
		printf("%d ", T->data);
		f(T->left);
		f(T->right);
	}
}


int main() {
	char ch;
	int pTList[200], iTList[200], len;
	for(int i = 0; 1; i++) {
		scanf("%d", &iTList[i]);
		ch = getchar();
		if(ch == '\n') {
			len = i+1;
			break;
		}
	}
	for(int i = 0; i < len; i++) {
		scanf("%d", &pTList[i]);
		ch = getchar();
		if(ch == '\n') break;
	}
	BiTNode *T = NULL;
	int i = len-1;
	usingInorderTListAndPostorderTListCreateTree(&T, pTList, iTList, &i, 0, len);
	f(T);
}