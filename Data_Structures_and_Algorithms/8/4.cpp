#include <bits/stdc++.h>
using namespace std;
array<int, 20000> a;
int res;

void merge(int begin1, int mid, int end1) {
    array<int, 20000> b, c;
    int l1 = 0, l2 = 0;
    for(int i = begin1; i <= mid; ++i) {
        b[l1++] = a[i];
    }
    for(int i = mid+1; i <= end1; ++i) {
        c[l2++] = a[i];
    }
    int i = 0, j = 0, k = begin1;
    while(j < l2 && i < l1) {
        if(b[i] <= c[j]) {
            a[k] = b[i++];
            res += mid+j-k;
        } else {
            a[k] = c[j++];
        }
        ++k;
    }
    while(i < l1) a[k++] = b[i++];
    while(j < l2) a[k++] = c[j++];
}

void mergesort(int begin1, int end1) {
    if(begin1 == end1) return;
    mergesort(begin1, (begin1+end1)/2);
    mergesort((begin1+end1)/2+1, end1);
    merge(begin1, (begin1+end1)/2, end1);
}

int main() {
    int N;
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
        }
        mergesort(0, N-1);
        printf("%d\n", res);
        res = 0;
    }
}