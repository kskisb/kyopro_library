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

// 素因数分解の結果を map で返す サイズ 0 なら 1
map<ll, ll> prime_factorization(ll N) {
  map<ll, ll> res;
  for(ll i=2; i*i<=N; i++) {
    while(N%i == 0) {
      N /= i;
      res[i]++;
    }
  }
  if(N >= 2) res[N]++;
  return res;
}

// 素因数分解をするプログラム
int main() {
  cout << "素因数分解をしたい正の整数を入力してください：";
  ll N;
  cin >> N;

  map<ll, ll> m = prime_factorization(N);
  for(auto i : m) cout << i.first << " " << i.second << endl;
  cout << m.size() << endl;
}