//
//  main.cpp
//  sjtu-oj-1019
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

bool check(const char* s) {
    //cout << "--->" << s << "<-----" << endl;
    
    int l = (int)strlen(s);
    int count = 0;
    for (int i = 0; i < l; ++i) {
        count += (s[i] == '(') ? 1 : -1;
        if (count < 0) return false;
    }
    return (count == 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    
    char buffer[200];
    for (int i = 0; i < n; ++i) {
        cin >> buffer;
        cout << (check(buffer) ? "YES" : "NO") << endl;
    }
}
