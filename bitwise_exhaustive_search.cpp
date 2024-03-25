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
#define rep(i, l, r) for(ll i=l; i<r; i++)
#define rrep(i, l, r) for(ll i=r-1; i>=l; i--)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    rep(bit, 0, 1<<N) {
        vector<int> tmp;
        rep(i, 0, N) {
            // 1 の場合、選ぶ
            if(bit / (1<<i) % 2 != 0) tmp.push_back(A[i]);
        }
    }
}