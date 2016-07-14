//
//  main.cpp
//  sjtu-oj-1012
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
using namespace std;

int f[220000];
unsigned long long fc[220000];
int step[220000];
int s, t;

static inline int gcd(int a, int b) {
    while (1) {
        if (b == 0) return a;
        else {
            int temp = a;
            a = b;
            b = temp % b;
        }
    }
}

static inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void calc_step(int s, int t) {
    for (int i = s; i <= t; ++i)
        step[i] = lcm(i, 100) / 100;
}

int main(int argc, const char * argv[]) {
    cin >> s >> t;
    calc_step(s, t);
    
    for (int i = s; i <= t; ++i) f[i] = fc[i] = 1;
    
    int res = -1;
    unsigned long long resc = 0;
    for (int i = s; i <= t; ++i) {
        for (int iter = i + step[i]; iter <= t; iter += step[i]) {
            if (f[iter] < f[i] + 1) {
                f[iter] = f[i] + 1;
                fc[iter] = fc[i];
            }
            else if (f[iter] == f[i] + 1) fc[iter] += fc[i];
        }
        
//        cout << i << endl;
//        for (int i = s; i <= t; ++i)
//            printf("%d(f: %d, fc:%d) ", i, f[i], fc[i]);
//        cout << "\n" << endl;
        
        if (res < f[i]) res = f[i];
    }
    
    for (int i = s; i <= t; ++i) if (res == f[i]) resc += fc[i];
    cout << res << endl << resc << endl;
}
