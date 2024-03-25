#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    int N, Tsum = 0; cin >> N;
    veci T(N+1);
    rep(i, 1, N+1) {
        cin >> T[i];
        Tsum += T[i];
    }

    vector<vector<bool>> dp(N+1, vector<bool>(Tsum+1, false));
    dp[0][0] = true;

    rep(i, 1, N+1) {
        rep(j, 0, Tsum+1) {
            if(j >= T[i] && (dp[i-1][j] || dp[i-1][j-T[i]])) dp[i][j] = true;
            if(dp[i-1][j]) dp[i][j] = true;
        }
    }
}