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

vector<int> bfs(int s) {
    // todoリスト を表すキュー
    queue<int> que;

    // dist[v] は始点 s から頂点 v への最短経路長
    vector<int> dist(N, -1);

    // 最初に始点 s を todoリスト にセットする
    dist[s] = 0;
    que.push(s);

    // todoリスト が空になるまで探索する
    while(!que.empty()) {
        // todoリストから頂点 v を取り出す
        int v = que.front();
        que.pop();

        // v に直接つながる頂点を全探索
        for(auto v2 : G[v]) {
            // v2 がすでに探索済みの場合はスキップ
            if(dist[v2] != -1) continue;

            // v2 を新たに todoリスト に追加
            que.push(v2);

            // v2 の dist の値を更新
            dist[v2] = dist[v] + 1;
        }
    }

    // 最短経路長を表す配列を返す
    return dist;
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

    veci d = bfs(0);
    for(int i=0; i<N; i++) cout << d[i] << " ";
    cout << endl;
}