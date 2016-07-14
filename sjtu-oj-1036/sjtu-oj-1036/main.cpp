//
//  main.cpp
//  sjtu-oj-1036
//
//  Created by vivi on 6/29/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void calc1(unsigned long long* a, int n) {
    if (n <= 3) {
        cout << 0 << " " << max(a[0], max(a[1], a[2])) << endl;
        return;
    }
    
    unsigned long long total_wait = 0;
    unsigned long long max_time = -1;
    unsigned long long* f = new unsigned long long[n];
    f[0] = f[1] = f[2] = 0;
    
    for (int i = 3; i < n; ++i) {
        f[i] = f[i - 3] + a[i - 3];
        total_wait += f[i];
    }
    
    max_time = max(f[n - 1] + a[n - 1], max(f[n - 2] + a[n - 2], f[n - 3] + a[n - 3]));
    cout << total_wait << " " << max_time << endl;
    
    delete [] f;
}

void calc2(unsigned long long* a, int n) {    
    if (n <= 3) {
        cout << 0 << " " << max(a[0], max(a[1], a[2])) << endl;
        return;
    }
    
    unsigned long long wait_t[3];
    wait_t[0] = a[0]; wait_t[1] = a[1]; wait_t[2] = a[2];
    
    unsigned long long total_wait = 0;
    unsigned long long max_time = 0;
    
    for (int i = 3; i < n; ++i) {
        int s = 0; //select
        if (wait_t[s] > wait_t[1]) s = 1;
        if (wait_t[s] > wait_t[2]) s = 2;
        
        total_wait += wait_t[s];
        wait_t[s] += a[i];
        max_time = max(max_time, wait_t[s]);
    }
    
    cout << total_wait << " " << max_time << endl;
}

int main(int argc, const char * argv[]) {
    int n; cin >> n;
    unsigned long long* a = new unsigned long long[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    calc1(a, n);
    calc2(a, n);
    
    delete [] a;
}
