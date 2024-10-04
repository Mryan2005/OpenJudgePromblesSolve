#include <bits/stdc++.h>
using namespace std;

long long int a[500000], res = 0;

long Partition(long low, long high) {
    int temp = a[low];
    while(low < high) {
        while(low < high && a[high] >= temp) --high;
        a[low] = a[high];
        while(low < high && a[low] <= temp) ++low;
        a[high] = a[low];
    }
    ++res;
    a[low] = temp;
    return low;
}

void quickSort(long low, long high) {
    if(low < high) {
        long p = Partition(low, high);
        quickSort(low, p-1);
        quickSort(p+1, high);
    }
}

int main() {
    long n;
    while(1) {
        res = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        quickSort(0, n);
    }
}