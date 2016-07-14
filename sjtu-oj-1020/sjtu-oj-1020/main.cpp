//
//  main.cpp
//  sjtu-oj-1020
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int a; cin >> a;
    int count;
    
    printf("%d=", a);
    for (int i = 2; i <= (int)sqrt(a); ++i) {
        count = 0;
        while (a % i == 0) { a /= i; ++count; }
        if (count) printf("%d(%d)", i, count);
    }
    if (a != 1) printf("%d(%d)", a, 1);
}
