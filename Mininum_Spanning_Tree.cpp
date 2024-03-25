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

// 頂点 N, 辺の数 M
int N, M;

class UnionFind {
public:
    // 親の番号を格納
    veci parent;
    // 自分がいるグループの辺の数を格納
    veci sides;

    UnionFind(int N) {
        parent = veci(N, -1);
        sides = veci(N, 0);
    }

    // 頂点 A のグループの 根 を返す
    int root(int A) {
        if(parent[A] < 0) return A;
        return parent[A] = root(parent[A]);
    }

    // 頂点 A の属しているグループの頂点数を返す
    int size(int A) {
        return -parent[root(A)];
    }

    // A と B を結合
    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if(A == B) {
            sides[A]++;
            return false;
        }

        if(size(A) < size(B)) swap(A, B);

        parent[A] += parent[B];
        parent[B] = A;
        sides[A]++;
        
        return true;
    }
};

int main() {
    cin >> N >> M;
    UnionFind UN(N);

    vector<pair<int , pair<int, int>>> weighted_edge(M);
    rep(i, 0, M) {
        int a, b, c; cin >> a >> b >> c;
        weighted_edge[i] = make_pair(c, make_pair(a, b));
    }

    sort(weighted_edge.begin(), weighted_edge.end());

    ll ans = 0; // MST の辺の重みの総和
    rep(i, 0, M) {  // ここで rrep にすると 最大全域木 になる
        int u = weighted_edge[i].second.first - 1;
        int v = weighted_edge[i].second.second - 1;
        if(UN.root(u) == UN.root(v)) continue;
        else {
            ans += weighted_edge[i].first;
            UN.connect(u, v);
        }
    }
    cout << ans << endl;
}