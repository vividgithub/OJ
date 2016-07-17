/*                  
 _   _ (_) _     (_)      ___    _      _| |   __         (_)   _ _   ___ ___  
 ( ) ( )| |( ) ( )| |    /'___) /'_`\  /'_` | /'__`\       | | /'_` )/' _ ` _ `\
 | \_/ || || \_/ || |   ( (___ ( (_) )( (_| |(  ___/       | |( (_| || ( ) ( ) |
 `\___/'(_)`\___/'(_)   `\____)`\___/'`\__,_)`\____)    _  | |`\__,_)(_) (_) (_)
                                                       ( )_| |                  
                                                       `\___/'                                                                     
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

#define FOR(_i, _a, _b) for (auto _i = (_a); _i != (_b); ++_i)
#define REP(_i, _b) FOR(_i, 0, _b)

template<class T>
T bins(T left, T right, function<bool(T)> fulfill) {
    if (!fulfill(left)) return -1;
    else if (fulfill(right)) return right;
    
    T l, r;
    for (l = left, r = right; l < r; ) {
        auto mid = ((l + r) >> 1) + 1;
        if (fulfill(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int n, q;
int num[300000];

long long calc_idx(int val) {
    long long now_idx = 0;
    
    FOR(i, 0, n) {
        int l = bins<int>(i, n - 1, [i, val] (int idx) -> bool {
            if (i > 0) return num[idx] - num[i - 1] <= val;
            else return num[idx] <= val;
        });
        if (l != -1) now_idx += l - i + 1;
    }
    
    return now_idx - 1;
}

int val_at_idx(long long idx) {
    return bins<int>(0, 200000 * 100, [idx](int val) -> bool {
        return idx > calc_idx(val);
    }) + 1;
}

void solve(int _) {
    cin >> n >> q;
    FOR(i, 0, n) { 
        cin >> num[i];
        if (i) num[i] += num[i - 1];
    }
    
    printf("Case #%d:\n", _);
    FOR(i, 0, q) {
        long long l, r; cin >> l >> r; l--; r--;
        if (l == 0) printf("%d\n", val_at_idx(r));
        else printf("%d\n", val_at_idx(r) - val_at_idx(l - 1));
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - pr - 4/google code jam - 2017 - pr - 4/input.txt", "r", stdin);
    //freopen("/Users/vivi/Developer/OJ/google code jam - 2017 - pr - 4/google code jam - 2017 - pr - 4/output.txt", "w", stdout);
    int t; cin >> t; FOR(i, 1, t + 1) solve(i);
}