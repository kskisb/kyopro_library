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

Graph G;
int N, M;

int main() {
    cin >> M;

    set<string> S;
    vector<int> u, v;
    map<string, int> names;

    int num = 0;
    rep(i, 0, M) {
        string s, t; cin >> s >> t;
        S.insert(s); S.insert(t);
        if(!names[s]) {
            num++; names[s] = num;
        }
        u.push_back(names[s]-1);
        if(!names[t]) {
            num++; names[t] = num;
        }
        v.push_back(names[t]-1);
    }

    N = S.size();
    G.assign(N, veci());
    rep(i, 0, M) G[u[i]].push_back(v[i]);

}