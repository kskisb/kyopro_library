#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvveci = vector<vveci>;
using vvecll = vector<vecll>;
using vvvecll = vector<vvecll>;
using vvecd = vector<vecd>;
using Graph = vector<vector<int>>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int N, M;
Graph G;
veci color;

bool dfs(int v, int now = 0) {
    color[v] = now;
    for(auto nex : G[v]) {
        if(color[nex] != -1) {
            if(color[nex] == now) return false;
            continue;
        }
        if(!dfs(nex, 1-now)) return false;
    }
    return true;
}

int main() {
    cin >> N >> M;
    G.assign(N, veci());
    color.assign(N, -1);
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool isbipartite = true;
    rep(i, 0, N) {
        if(color[i] != -1) continue;
        if(!dfs(i)) isbipartite = false;
    }
}