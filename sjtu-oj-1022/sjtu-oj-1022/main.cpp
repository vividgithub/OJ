//
//  main.cpp
//  sjtu-oj-1022
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#define BASE 2010

struct fibmat {
    int a0, a1, a2, a3;
};

fibmat mul(fibmat a1, fibmat a2) {
    return fibmat {
        (a1.a0 * a2.a0 + a1.a1 * a2.a2) % BASE,
        (a1.a0 * a2.a1 + a1.a1 * a2.a3) % BASE,
        (a1.a2 * a2.a0 + a1.a3 * a2.a2) % BASE,
        (a1.a2 * a2.a1 + a1.a3 * a2.a3) % BASE
    };
}

fibmat times(unsigned long long n) {
    static fibmat base {1, 1, 1, 0};
    if (n == 1) return base;
    fibmat sub = times(n >> 1);
    fibmat sub2 = mul(sub, sub);
    return ((n & 1) == 0 ? sub2 : mul(sub2, base));
}

int main(int argc, const char * argv[]) {
    using namespace std;
    unsigned long long n; cin >> n;
    cout << (n == 0 ? 0 : times(n).a2) << endl;
}
