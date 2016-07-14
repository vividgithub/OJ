//
//  main.cpp
//  sjtu-oj-1031
//
//  Created by vivi on 6/26/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#define MAXN 150
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x < y ? y : x)

int m[MAXN][MAXN];
int n;
int min_h = 2000;
int max_h = -2000;

int check(int n, int h_th_min, int h_th_max) {
    struct q_struct { int x, y, min_h, max_h; };
    
    static bool visited[MAXN][MAXN];
    static q_struct q[MAXN * MAXN];
    static int ss, tt;
    static int kx[] = {0, 0, 1, -1};
    static int ky[] = {1, -1, 0, 0};
    
    if (m[0][0] < h_th_min || m[0][0] > h_th_max) { return -1; }
    
    memset(visited, 0, sizeof(bool) * MAXN * MAXN);
    visited[0][0] =  true;
    q[0].x = q[0].y = 0; q[0].min_h = q[0].max_h = m[0][0];
    
    for (ss = tt = 0; ss <= tt; ++ss) for (int k = 0; k < 4; ++k) {
        int xx = q[ss].x + kx[k]; 
        int yy = q[ss].y + ky[k];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && m[xx][yy] >= h_th_min && m[xx][yy] <= h_th_max && !visited[xx][yy]) {
            visited[xx][yy] = true;
            ++tt;
            q[tt].x = xx; q[tt].y = yy;
            q[tt].min_h = MIN(q[ss].min_h, m[xx][yy]);
            q[tt].max_h = MAX(q[ss].max_h, m[xx][yy]);
            
            if (xx == n - 1 && yy == n - 1) return (q[tt].max_h - q[tt].min_h);
        }
    }
    
    //failed:
    return -1;
}

int check_h(int n, int h, int min_h, int max_h) {
    int check_val;
    for (int i = min_h; i + h <= max_h; ++i) if ((check_val = check(n, i, i + h)) != -1) {
//        printf("Checking: %d %d --> true(%d)\n", i, i +h, check_val);
        return check_val;
    }
//    printf("Checking: %d--> false\n", h);
    return -1;
}

int check_map(int n, int min_h, int max_h) {
    int l = 0;
    int r = max_h - min_h;
    int mid, check;
    
    while (l < r) {
        mid = (l + r) >> 1;
        check = check_h(n, mid, min_h, max_h);
        if (check == -1) l = mid + 1;
        else r = check;
    }
    
    return l;
}

int main(int argc, const char * argv[]) {
    using namespace std;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> m[i][j];
        min_h = MIN(min_h, m[i][j]);
        max_h = MAX(max_h, m[i][j]);
    }
    cout << check_map(n, min_h, max_h);
}
