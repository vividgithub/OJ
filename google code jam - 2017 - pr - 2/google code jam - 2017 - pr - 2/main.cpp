//
//  main.cpp
//  google code jam - 2017 - pr - 2
//
//  Created by vivi on 7/10/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define ul unsigned long
#define FOR(_i, _a, _b) for (auto _i = (_a); _i != (_b); ++_i)

ll diff(const map<ul, ul>& a, const map<ul, ul> b) {
    ll res = 0;
    
    auto ib = b.begin();
    FOR (ia, a.begin(), a.end()) {
        while (ib != b.end() && ib->first < ia->first) ++ib;
        if (ib->first == ia->first) res += ib->second * ia->second;
    }
    
    return res;
}

ll solve() {
    int n; ul k;
    ul a[2000], b[2000], c[2000], d[2000];
    
    cin >> n >> k;
    FOR (i, 0, n) cin >> a[i];
    FOR (i, 0, n) cin >> b[i];
    FOR (i, 0, n) cin >> c[i];
    FOR (i, 0, n) cin >> d[i];
    
    map<ul, ul> pm, qm;
    
    FOR(ia, 0, n) FOR(ib, 0, n) {
        ul key = a[ia] ^ b[ib];
        if (pm.find(key) == pm.end()) pm.insert(make_pair(key, 1));
        else ++pm[key];
    }
//    FOR (i, pm.begin(), pm.end()) {
//        cout << "PM " << i->first << " " << i->second << endl;
//    }
    
    FOR(ic, 0, n) FOR(id, 0, n) {
        ul key = c[ic] ^ d[id] ^ k;
        if (qm.find(key) == qm.end()) qm.insert(make_pair(key, 1));
        else ++qm[key];
    }
//    FOR (i, qm.begin(), qm.end()) {
//        cout << "QM " << i->first << " " << i->second << endl;
//    }
    
    return diff(pm, qm);
}

int main(int argc, const char * argv[]) {
    freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - pr - 2/google code jam - 2017 - pr - 2/input.txt", "r", stdin);
    freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - pr - 2/google code jam - 2017 - pr - 2/output.txt", "w", stdout);
    
    int t; cin >> t;
    FOR(_, 1, t + 1) printf("Case #%d: %lld\n", _, solve());
}
