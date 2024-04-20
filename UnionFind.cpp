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

// 頂点 N, 辺の数 M
int N, M;

class UnionFind {
public:
    // 親の番号を格納
    vector<int> parent;
    // 自分がいるグループの辺の数を格納
    vector<int> sides;

    UnionFind(int N) {
        parent = vector<int>(N, -1);
        sides = vector<int>(N, 0);
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

    for(int i=0; i<M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if(UN.root(u) == UN.root(v)) // true なら ループあり
        UN.connect(u, v);
    }
}