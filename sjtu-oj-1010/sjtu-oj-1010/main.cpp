//
//  main.cpp
//  sjtu-oj-1010
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int cur = 0;
    int save = 0;
    int spend;
    
    for (int i = 1; i <= 12; ++i) {
        cin >> spend;
        cur += 300 - spend;
        if (cur < 0) {
            cout << -i << endl;
            return 0;
        }
        
        save += cur / 100;
        cur %= 100;
    }
    
    cout << save * 120 + cur << endl;
}
