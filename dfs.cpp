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

int N, M;
Graph G;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;

    for(auto next : G[now]) { 
        if(visited[next]) continue;
        dfs(next);
    }
}

int main() {
    cin >> N >> M;

    G.assign(N, veci());
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    visited.assign(N, false);
    dfs(0);
}