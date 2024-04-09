#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;

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

    vector<pair<int , pair<int, int>>> weighted_edge(M);
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        weighted_edge[i] = make_pair(c, make_pair(a, b));
    }

    sort(weighted_edge.begin(), weighted_edge.end());

    ll ans = 0; // MST の辺の重みの総和
    for(int i=0; i<M; i++) {  // ここで 逆順(i: M-1 -> 0) にすると 最大全域木 になる
        int u = weighted_edge[i].second.first;
        int v = weighted_edge[i].second.second;
        if(UN.root(u) == UN.root(v)) continue;
        else {
            ans += weighted_edge[i].first;
            UN.connect(u, v);
        }
    }
    cout << ans << endl;
}