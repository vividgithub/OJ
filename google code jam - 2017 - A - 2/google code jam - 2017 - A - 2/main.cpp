//
//  main.cpp
//  google code jam - 2017 - A - 2
//
//  Created by vivi on 7/10/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdlib>
#include <cmath>
using namespace std;

#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); ++_i)

struct qstruct {
    int x, y, h;
};

bool operator<(const qstruct& a, const qstruct& b) { return a.h > b.h; }

int solve() {
    static int kx[] = {-1, 1, 0, 0};
    static int ky[] = {0, 0, -1, 1};
    
    int n, m;
    int matrix[200][200];
    bool used[200][200];
    int res = 0;
    priority_queue<qstruct> q;
    
    cin >> n >> m;
    memset(used, 0, sizeof(used));
    FOR(i, 0, n) FOR(j, 0, m) {
        cin >> matrix[i][j];
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { 
            q.push(qstruct{i, j , matrix[i][j]});
            used[i][j] = true;
        }
    }
    
    while (!q.empty()) {
        auto now = q.top(); q.pop();
        FOR(k, 0, 4) {
            int x = now.x + kx[k];
            int y = now.y + ky[k];
            if (x >= 0 && y >= 0 && x < n && y < m && !used[x][y]) {
                used[x][y] = true;
                if (now.h > matrix[x][y]) { 
                    res += now.h - matrix[x][y];
                    matrix[x][y] = now.h;
                }
                q.push(qstruct{x, y, matrix[x][y]});
            }
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - A - 2/google code jam - 2017 - A - 2/input.txt", "r", stdin);
    freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - A - 2/google code jam - 2017 - A - 2/output.txt", "w", stdout);
    
    int t; cin >> t;
    
    for (int _ = 1; _ <= t; ++_)
        printf("Case #%d: %d\n", _, solve());
}
