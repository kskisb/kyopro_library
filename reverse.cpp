#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
using Graph = vector<vector<int>>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    int N = 15;
    veci a(N);
    rep(i, 0, N) a[i] = i;

    rep(i, 0, N) printf("%2d ", a[i]);
    cout << endl;
    
    int l = 4, r = 11;
    rep(i, l, (l+r)/2 + 1) {
        swap(a[i], a[r-i+l]);
    }

    rep(i, 0, N) printf("%2d ", a[i]);
    cout << endl;
}