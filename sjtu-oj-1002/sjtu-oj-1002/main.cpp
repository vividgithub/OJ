//
//  main.cpp
//  sjtu-oj-1002
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>

int H, W;
int h, w;
int sum[1000][1000];

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int val;
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            cin >> val;
            if (i == 0 && j == 0) sum[i][j] = val;
            else if (i == 0) sum[i][j] = sum[i][j - 1] + val;
            else if (j == 0) sum[i][j] = sum[i - 1][j] + val;
            else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val;
        }
    cin >> h >> w;
    
    int max_val = -1;
    int a0, a1, a2, a3;
    for (int i = h - 1; i < H; ++i)
        for (int j = w - 1; j < W; ++j) {
            int ii = i - h;
            int jj = j - w;
            a0 = (ii >= 0 && jj >= 0) ? sum[ii][jj] : 0;
            a1 = (ii >= 0) ? sum[ii][j] : 0;
            a2 = (jj >= 0) ? sum[i][jj] : 0;
            a3 = sum[i][j] + a0 - a1 - a2;
            max_val = (max_val < a3) ? a3 : max_val;
        }
    
    cout << max_val << endl;
}
