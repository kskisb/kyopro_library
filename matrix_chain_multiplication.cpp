#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// 連鎖行列積問題

int main() {
    int n; cin >> n;
    vector<vector<long long> > dp(n, vector<long long>(n, LLONG_MAX));
    vector<long long> mat_r(n), mat_c(n);
    for(int i=0; i<n; i++) cin >> mat_r[i] >> mat_c[i];
    for(int i=0; i<n; i++) dp[i][i] = 0;

    for(int i=n-2; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            for(int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + mat_r[i]*mat_c[k]*mat_c[j]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
}