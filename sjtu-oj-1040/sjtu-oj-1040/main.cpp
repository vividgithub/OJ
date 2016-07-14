//
//  main.cpp
//  sjtu-oj-1040
//
//  Created by vivi on 6/27/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    using namespace std;
    int n; cin >> n;
    
    int* pl = new int[n];
    int* pr = new int[n];
    memset(pl, 255, sizeof(int) * n);
    memset(pr, 255, sizeof(int) * n);
    
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        if (pl[p] == -1) pl[p] = i;
        else pr[p] = i;
    }
    
    int* q = new int[n];
    q[0] = 0;
    int ss, tt;
    for (ss = tt = 0; ss <= tt; ++ss) {
        if (pl[q[ss]] != -1) q[++tt] = pl[q[ss]];
        if (pr[q[ss]] != -1) q[++tt] = pr[q[ss]];
    }
    
    for (int i = 0; i < n; ++i)
        cout << q[i] << " ";
}
