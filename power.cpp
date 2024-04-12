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

// m^n mod 1000000007 を返す
ll power(ll m, ll n) {
    ll p = m, ans = 1;
    for(int i=0; i<60; i++) {
        ll d = (1LL << i);
        if((n/d)%2) ans = (ans*p)%mod;
        p = (p*p)%mod;
    }
    return ans;
}

int main() {
    ll m, n; cin >> m >> n;
    cout << power(m, n) << endl;
}