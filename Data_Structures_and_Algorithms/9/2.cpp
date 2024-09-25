#include <bits/stdc++.h>
using namespace std;

struct LoserTree {
    int index;
    LoserTree *r, *l;
};

/*
 * input: begin1, end1, vector, &winner
 * return: LoserTree* Loser, winner
 */
void createLoserTree(int begin1, int end1, vector<int> nums, LoserTree **winner, LoserTree **Loser) {
    if(begin1 == end1) {    // 只有一人
        *winner = (LoserTree*)malloc(sizeof(LoserTree));
        (*winner)->index = begin1;
        *Loser = (*winner)->r = (*winner)->l = NULL;
        return;
    } else if(begin1 > end1) {
        *winner = *Loser = NULL;
        return;    // 越界
    }
    LoserTree *winner1, *winner2, *Loser1, *Loser2;
    int mid = (begin1+end1)/2;
    createLoserTree(begin1, mid, nums, &winner1, &Loser1);
    createLoserTree(mid == begin1? mid+1: mid, end1, nums, &winner2, &Loser2);
    if(winner1 && winner2) {
        if(nums[winner1->index] <= nums[winner2->index]) {
            (*Loser)->index = winner2->index;
            *winner = winner1;
            (*Loser)->l = Loser1;
            (*Loser)->r = Loser2;
        } else {
            (*Loser)->index = winner1->index;
            *winner = winner2;
            (*Loser)->l = Loser1;
            (*Loser)->r = Loser2;
        }
    }
    return;
}

int main() {
    int n, m, temp;   // itemsCount, changeCount
    vector<int> nums;
    scanf("%d %d", &n, &m);
    nums.reserve(n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &temp);
        nums.insert(nums.end(), temp);
    }
    LoserTree *Loser, *Winner;
    createLoserTree(0, n-1, nums, &Winner, &Loser);
}