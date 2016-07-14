//
//  main.cpp
//  sjtu-oj-1024
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
using namespace std;

void m_sort(int* a, int l, int r, int n) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    
    m_sort(a, l, mid, n);
    m_sort(a, mid + 1, r, n);

    int u = mid + 1;
    int v = l + n;
    for (int i = l; i <= mid; ++i) {
        while (u <= r && a[u] < a[i]) a[v++] = a[u++];
        a[v++] = a[i];
    }
    while (u <= r) a[v++] = a[u++];
    
    for (int i = l; i <= r; ++i) a[i] = a[i + n];
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int* a = new int[2 * n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    m_sort(a, 0, n - 1, n);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
}
