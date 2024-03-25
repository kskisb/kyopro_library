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

ll binary_to_num(string bin) {
    ll twopow = 1, res = 0;

    rrep(i, 0, bin.size()) {
        if(bin[i] == '1') res += twopow;
        twopow *= 2;
    }

    return res;
}

int main() {
    string bin; cin >> bin;
    cout << binary_to_num(bin) << endl;
}