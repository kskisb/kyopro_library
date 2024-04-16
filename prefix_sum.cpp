#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
ll mod = 1000000007;

// 累積和を出力する
vector<ll> prefix_sum(int N, vector<ll> A) {
    vector<ll> p_sum(N+1, 0);
    for(int i=1; i<N+1; i++) p_sum[i] = p_sum[i-1] + A[i];
    return p_sum;
}

// 2次元累積和を出力する
vector<vector<ll>> prefix_sum_2D(vector<vector<ll>> a) {
    int H = a.size(), W = a[0].size();
    vector<vector<ll>> res(H, vector<ll>(W, 0));
    for(int i=1; i<H; i++) {
        for(int j=1; j<W; j++) {
            res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + a[i][j];
        }
    }
    return res;
}

int main() {
    // k(1..N)個の連続する区間の総和の最大値を求める
    int N; cin >> N;
    vector<ll> A(N+1);
    for(int i=1; i<N+1; i++) cin >> A[i];
    vector<ll> p_sum = prefix_sum(N, A);

    vector<ll> ans;
    for(int k=1; k<N+1; k++) {
        ll tmp = 0;
        for(int j=0; j+k<N+1; j++) {
            tmp = max(tmp, p_sum[j+k]-p_sum[j]);
        }
        ans.push_back(tmp);
    }

    // 左上(a, b) から 右下(c, d) の範囲の総和を求める
    int n, m; cin >> n >> m;
    vector<ll> field(N+1, vector<ll>(M+1, 0));
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<M+1; j++) cin >> field[i][j];
    }
    vector<vector<ll>> p_sum_2D_J = prefix_sum_2D(a);
    int a, b, c, d;
    ll res = field[c][d] - field[c][b-1] - field[a-1][d] + field[a-1][b-1];
}