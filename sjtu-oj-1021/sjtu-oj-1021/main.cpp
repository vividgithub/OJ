//
//  main.cpp
//  sjtu-oj-1021
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cstdio>

int matrix[150][150];

void draw(int y, int x, int n, int count) {
    if (n == 1) { matrix[y][x] = count++; return; }
    else if (n == 0) return;
    
    for (int i = 0; i < n - 1; ++i) matrix[y][x++] = count++;
    for (int i = 0; i < n - 1; ++i) matrix[y++][x] = count++;
    for (int i = 0; i < n - 1; ++i) matrix[y][x--] = count++;
    for (int i = 0; i < n - 1; ++i) matrix[y--][x] = count++;
    draw(y + 1, x + 1, n - 2, count);
}

int main(int argc, const char * argv[]) {
    using namespace std;
    int n; cin >> n;
    draw(0, 0, n, 1);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%6d", matrix[i][j]);
        printf("\n");
    }
}
