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

// エラトステネスの篩 O(nloglogn)
vector<bool> Seive_of_Eratosthenes(ll N) {
    vector<bool> isprime(N+1, true);
    isprime[0] = false; isprime[1] = false;
    for(ll i=2; i*i<=N; i++) {
        if(!isprime[i]) continue;
        for(ll j=i*i; j<=N; j+=i) isprime[j] = false;
    }
    return isprime;
}

int main() {
    ll N; cin >> N;
    vector<bool> seive = Seive_of_Eratosthenes(N);
    if(seive[N]) cout << N << " is prime." << endl;
    else cout << N << " is not prime." << endl;
}