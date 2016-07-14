//
//  main.cpp
//  sjtu-oj-1004
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>

int m, t, f, u, d;
int sum[120000];

int bin_search(int* a, int l, int r, int st) {
    while (l < r) {
        int mid = ((l + r) >> 1) + 1;
        if (a[mid] > st) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main(int argc, const char * argv[]) {
    using namespace std;
    
    char c;
    cin >> m >> t >> u >> f >> d;
    
    int pre = 0;
    for (int i = 0; i < t; ++i) {
        cin >> c;
        sum[i] += pre + (c == 'f' ? (f << 1) : (u + d));
        pre = sum[i];
    }
    
    cout << bin_search((int*)sum, 0, t - 1, m) + 1 << endl;
}
