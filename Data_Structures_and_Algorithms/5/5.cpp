#include <bits/stdc++.h>
using namespace std;
struct BinTree {
	char data;
	BinTree *l, *r;
};

void createBinTree(BinTree **T, int flag, queue<string> *q) {
	string s;
	if(!(*q).empty() && (*q).front() == "0") {
		*T = NULL;
		return;
	}
	else if((*q).empty()) {
		cin >> s; 
		(*q).push(s);
	}
	if(s == "0") {
		*T = NULL;
		return;
	}
	if(!(*q).empty()) {
		s = (*q).front();
		(*q).pop();
	}
	int i = 0;
	for(; s[i] == '-'; i++);
	if(i < flag) {
		*T = NULL;
		(*q).push(s);
		return;
	}
	if(s[i] != '*') {
		*T = (BinTree*)malloc(sizeof(BinTree));
		(*T)->data = s[i];
	} else {
		*T = NULL;
	}
	if(*T) createBinTree(&((*T)->l), flag+1, q);
	if(*T) createBinTree(&((*T)->r), flag+1, q);
}

void preRead(BinTree *T) {
	if(T) {
		printf("%c", T->data);
		preRead(T->l);
		preRead(T->r);
	}
}

void midRead(BinTree *T) {
	if(T) {
		midRead(T->l);
		printf("%c", T->data);
		midRead(T->r);
	}
}

void proRead(BinTree *T) {
	if(T) {
		proRead(T->l);
		proRead(T->r);
		printf("%c", T->data);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		BinTree *T = NULL;
		queue<string> q;
		createBinTree(&T, 0, &q);
		preRead(T);
		printf("\n");
		proRead(T);
		printf("\n");
		midRead(T);
		if(i < n-1) {
			printf("\n");
			printf("\n");
		}
	}
}