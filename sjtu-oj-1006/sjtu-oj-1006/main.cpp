//
//  main.cpp
//  sjtu-oj-1006
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>

#define MAX(a, b) ((a < b) ? b : a)
#define MIN(a, b) ((a < b) ? a : b) 

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int n; cin >> n;
    
    int pre_val, val, pre, now = -2147483648;
    int res = -2147483648;
    
    cin >> val;
    for (int i = 1; i < n; ++i) {
        pre_val = val;
        pre = now;
        cin >> val;
        now = MAX(pre, pre_val) + val;
        res = MAX(res, now);
    }
    
    if (res <= 0)
        cout << "Game Over" << endl;
    else 
        cout << res << endl;
}
