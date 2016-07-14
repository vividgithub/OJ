//
//  main.cpp
//  sjtu-oj-1048
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstring>

int n;
int tree_l[3000];
int tree_r[3000];
bool not_root[3000];
int ord[3000];

void output_ord(int r, int n) {
    ord[n] = r;
    if (tree_l[r] != -1) output_ord(tree_l[r], (n << 1) + 1);
    if (tree_r[r] != -1) output_ord(tree_r[r], (n << 1) + 2);
}

int main(int argc, const char * argv[]) {
    using namespace std;
    cin >> n;
    
    memset(not_root, 0, sizeof(bool) * n);
    memset(tree_l, 255, sizeof(int) * n);
    memset(tree_r, 255, sizeof(int) * n);
    int p, l, r;
    for (int i = 0; i < n / 2; ++i) {
        cin >> p >> l >> r;
        tree_l[p - 1] = l - 1; tree_r[p - 1] = r - 1;
        not_root[l - 1] = not_root[r - 1] = true;
    }
    
    int root = 0; while (not_root[root]) ++root;
    output_ord(root, 0);
    for (int i = 0; i < n; ++i) cout << ord[i] + 1 << "\n";
}
