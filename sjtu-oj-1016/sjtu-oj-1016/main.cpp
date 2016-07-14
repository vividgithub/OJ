//
//  main.cpp
//  sjtu-oj-1014
//
//  Created by vivi on 6/25/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX(a,b) ((a < b) ? b : a)

struct BigInt {
    int num[2000];
    int len;
};

char buffer[2000];
BigInt a, b, c;

void bigint_add(const BigInt& a, const BigInt& b, BigInt& c) {
    c.len = MAX(a.len, b.len);
    
    memset(c.num, 0, sizeof(int) * (c.len + 1));
    for (int i = 0; i < c.len; ++i) {
        int a_bit = (i < a.len ? a.num[i] : 0);
        int b_bit = (i < b.len ? b.num[i] : 0);
        c.num[i] += a_bit + b_bit;
        if (c.num[i] >= 10) {
            ++c.num[i + 1];
            c.num[i] -= 10;
        }
    }
    
    if (c.num[c.len]) ++c.len;
}

void bigint_init(BigInt& a, const char* buffer) {
    a.len = (int)strlen(buffer);
    for (int i = 0; i < a.len; ++i) 
        a.num[i] = buffer[a.len - 1 - i] - '0';
}

void bigint_output(const BigInt& a) {
    for (int i = a.len - 1; i >= 0 ; --i)
        cout << a.num[i];
    cout << endl;
}

int bigint_div_helper_cmp(const int* a, const int* b, const int la, const int lb) {
    if (la > lb) return 1;
    else if (la < lb) return -1;
    
    for (int i = 0; i < la; ++i) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}

int bigint_div_helper_minus(int* a, const int* b, int& la, const int lb) {
    int ai = la - 1; int bi = lb - 1;
    for (int i = 0; i < lb; ++i) a[ai--] -= b[bi--];
    
    ai = la;
    for (int i = la - 1; i >= 0; --i) {
        if (a[i] < 0) {
            a[i] += 10;
            --a[i - 1];
        }
        if (a[i]) ai = i;
    }
    
    for (int i = ai; i < la; ++i) a[i - ai] = a[i];
    return (la -= ai);
}

void debug_print(const int* a, const int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void bigint_div(const BigInt& a, const BigInt& b, BigInt& c) {
    static int base[2000];
    static int res[2000];
    static int left[2000];
    static int l_base, l_left, l_res;
    
    if (a.len == 1 && a.num[0] == 0) { c.len = 1;  c.num[0] = 0; return; }
    
    l_base = b.len; l_left = l_res = 0;
    for (int i = 0; i < b.len; ++i) base[i] = b.num[b.len - 1 - i];
    
    for (int i = a.len - 1; i >= 0; --i) {
        res[l_res++] = 0;
        left[l_left++] = a.num[i];
        while (bigint_div_helper_cmp(left, base, l_left, l_base) >= 0) {
            bigint_div_helper_minus(left, base, l_left, l_base);
            //debug_print(left, l_left);
            ++res[l_res - 1];
        }
    }
    
    c.len = 0;
    int u = 0; while (!res[u] && u < l_res - 1) ++u;
    for (int i = l_res - 1; i >= u; --i) c.num[c.len++] = res[i];
}

int main(int argc, const char * argv[]) {
    cin >> buffer;
    bigint_init(a, buffer);
    cin >> buffer;
    bigint_init(b, buffer);
    
    bigint_div(a, b, c);
    bigint_output(c);
}
