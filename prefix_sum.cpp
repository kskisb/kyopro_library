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

int main() {
    int N; cin >> N;
    vector<ll> A(N+1);
    for(int i=1; i<N+1; i++) cin >> A[i];
    vector<ll> p_sum = prefix_sum(N, A);

    // k(1..N)個の連続する区間の総和の最大値を求める
    vector<ll> ans;
    for(int k=1; k<N+1; k++) {
        ll tmp = 0;
        for(int j=0; j+k<N+1; j++) {
            tmp = max(tmp, p_sum[j+k]-p_sum[j]);
        }
        ans.push_back(tmp);
    }

    for(auto a : ans) cout << a << endl;
}