#include < algorithm >
#include < cstdio >
#include < cstring >
#include < vector >
using namespace std;

const int MAXN = 100010;
const int MAXM = 200010;
struct Trie {
	Trie *children[2];
	int value;
} root, pool[MAXN << 5], *ptr, emptyNode;
// Trie树是一棵二叉树，左孩子表示当前二进制位为0，右孩子表示当前二进制位为1
// 叶子节点额外保存value，表示当前路径对应的数，如根-左-右-右这个节点的value为(011)2=3

int n;
// 节点个数

int head[MAXN], succeed[MAXM], vertex[MAXM], weight[MAXM], now;
// head,succeed使用链表保存边表；vertex,weight存每条边的终点以及权值

int rootXor[MAXN];
// 每个点到根的路径的xor值

void addEdge(int u, int v, int w) {
	// 往链表中添加一条u->v，权值为w的边
	________(1)________
	// 新的节点的后继为u节点原来的链表头
	vertex[now] = v;
	// 新的边的终点为v
	weight[now] = w;
	// 新的边的权值为w
	head[u] = now++;
	// 指定u节点新的链表头为now
}

void readTree() {
	// 读入树
	memset(head, -1, sizeof head);
	now = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
}

void DFS(int x = 0, int father = -1) {
	// DFS求出每个点到0号点的路径的xor值，并填到rootXor数组中
	// 参数x表示当前递归到的节点，father表示当前点的父亲
	for (int now = head[x]; now != -1; now = succeed[now]) {
		// 遍历x节点的链表，找到所有x的出边
		int y = vertex[now];
		int w = weight[now];
		// 从x到y有一条权值为w的边
		if (________(2)________)
			continue;
		// 忽略返回父亲的边
		rootXor[y] = ________(3)________;
		// 计算rootXor[y]的值，为y到0号点的路径的xor值
		DFS(y, x);
	}
}

int getNthBit(int value, int nBit) {
	return value >> nBit & 1;
}

void insertTrie(Trie *node, int value, int nBit) {
	// 往Trie中插入value
	// 当前在node这个节点，处理到value的第nBit个bit
	// 如果nBit为-1，说明已经处理完毕，node为叶子节点
	if (nBit == -1)
		node->value = ________(4)________;
	else {
		bool bit = ________(5)________;
		// bit为0说明当前的节点应为node的左孩子
		// bit为1说明当前的节点应为node的右孩子
		if (!node->children[bit]) {
			node->children[bit] = ptr++;
			*node->children[bit] = emptyNode;
		}
		insertTrie(node->children[bit], value, nBit - 1);
	}
}

void buildTrie() {
	// 将所有rootXor[i]插入Trie中
	root = emptyNode;
	ptr = pool;
	for (int i = 0; i < n; i++)
		insertTrie(&root, rootXor[i], 30);
}

int queryTrie(Trie *node, int value, int nBit) {
	// 在Trie中查询与value的xor值最大的答案
	// 当前在node这个节点，处理到value的第nBit个bit
	// 如果nBit为-1，说明已经处理完毕，node为叶子节点
	if (nBit == -1)
		return node->value ^ value;
	else {
		bool bit = ________(5)________;
		// 同上
		if (node->children[!bit])
			return queryTrie(node->children[!bit], value, nBit - 1);
		else
			return queryTrie(node->children[bit], value, nBit - 1);
	}
}

int getAns() {
	// 将所有rootXor[i]在Trie中查询最大的xor答案
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, queryTrie(&root, rootXor[i], 30));
	return ans;
}

int main() {
	while (scanf("%d", &n) == 1) {
		readTree();
		DFS();
		buildTrie();
		printf("%d\n", getAns());
	}
	return 0;
}