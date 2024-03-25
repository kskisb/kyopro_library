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

    rep(i, 0, M) {
        int u, v; cin >> u >> v; u--; v--;
        if(UN.root(u) == UN.root(v)) // true なら ループあり
        UN.connect(a, b);
    }
}