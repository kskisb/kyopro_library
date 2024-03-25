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

string num_to_binary(ll N) {
    if(!N) return std::string("0");
    
    string str;
    while(N != 0) {
        if((N & 1) == 0) {
            str.insert(str.begin(), '0');
        } else {
            str.insert(str.begin(), '1');
        }
        N >>= 1;
    }
    return str;
}

int main() {
    ll N; cin >> N;
    cout << num_to_binary(N) << endl;
}