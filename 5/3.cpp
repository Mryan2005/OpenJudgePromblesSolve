#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *L;
	TreeNode *R;
};

void addNode(TreeNode **T, int data) {
	if(!*T) {
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = data;
		(*T)->L = (*T)->R = NULL;
	} else {
		TreeNode *p = *T;
		while(p) {
			if(data > p->data) {
				if(p->R) p = p->R;
				else break;
			} else if(data < p->data) {
				if(p->L) p = p->L;
				else break;
			} else if(data == p->data) {
				goto out;
			}
		}
		if(data > p->data) {
			p->R = (TreeNode*)malloc(sizeof(TreeNode));
			p = p->R;
			p->data = data;
			p->L = p->R = NULL;
		} else if(data < p->data) {
			p->L = (TreeNode*)malloc(sizeof(TreeNode));
			p = p->L;
			p->data = data;
			p->L = p->R = NULL;
		}
		out:;
	}
}

void readTree(TreeNode *T) {
	stack<TreeNode*> S;
	TreeNode *p = T;
	while (p) {
		printf("%d ", p->data);
		if (p->L) {
			S.push(p);
			p = p->L;
		} else if (p->R) p = p->R;
		else {
			while (!S.empty() && !p->R) {
				p = S.top();
				S.pop();
			}
			if (p->R) p = p->R;
			else break;
		}
	}
}

int main() {
	TreeNode *T = NULL;
	int num;
	while(cin >> num){
		addNode(&T, num);
	}
	readTree(T);
}