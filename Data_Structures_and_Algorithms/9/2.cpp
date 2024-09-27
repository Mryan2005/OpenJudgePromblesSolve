#include <bits/stdc++.h>
using namespace std;

struct LoserTreeNode {
    int index;
    int data;
};

/*
 * input: begin1, end1, vector, &winner
 * return: LoserTree* Loser, winner
 */
void createLoserTree(vector<int> nums, int level) {

}

int main() {
    int n, m, temp;   // itemsCount, changeCount
    vector<int> nums;
    deque<int> Q;
    scanf("%d %d", &n, &m);
    nums.reserve(n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &temp);
        nums.insert(nums.end(), temp);
        Q.push_back(i-1);
    }
    LoserTree *Loser, *Winner;
    createLoserTree(0, n-1, nums, &Winner, &Loser);
}