//
//  main.cpp
//  sjtu-oj-1034
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MIN(a,b) (a < b ? a : b)

int n, k;
int q[440000];
int q_pos[440000];
int ss = 0;
int tt = -1;
int num[440000];

static inline void q_push(int num, int pos) {
    while (ss <= tt && q[tt] < num) --tt;
    q[++tt] = num;
    q_pos[tt] = pos;
}

static inline void q_pop(int pos) {
    if (pos == q_pos[ss]) ++ss;
}

static inline int q_max() {
    return q[ss];
}

int main(int argc, const char * argv[]) {
    using namespace std;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) { scanf("%d", num + i); num[i + n] = num[i]; }
    for (int i = 0; i < k; ++i) { q_push(num[i], i); }
    
    int res = q_max();
    for (int i = k; i < (n << 1); ++i) {
        q_push(num[i], i); q_pop(i - k);
        res = MIN(q_max(), res);
    }
    cout << res << endl;
}
