//
//  main.cpp
//  sjtu-oj-1032
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int m, n; cin >> m >> n;
    if (m == 0) { cout << n + 1; return 0; }
    else if (m == 1) { cout << n + 2; return 0; }
    else if (m == 2) { cout << 2 * n + 3; return 0; }
    else {
        int bigint[400]; memset(bigint, 0, sizeof(int) * 400); bigint[0] = 1;
        
        //power
        for (int i = 0; i < n + 3; ++i) { 
            for (int j = 0; j < 400; ++j) bigint[j] *= 2;
            for (int j = 0; j < 400; ++j) if (bigint[j] >= 10) {
                bigint[j] -= 10;
                ++bigint[j + 1];
            }
        }
        
        //sub
        bigint[0] -= 3; 
        for (int i = 0; bigint[i] < 0; ++i) { bigint[i] += 10; --bigint[i + 1]; }
        
        //output
        int u = 399; while (bigint[u] == 0) --u;
        for (int i = u; i >= 0; --i) cout << bigint[i];
    }
}
