#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

vector<vector<pair<ll, ll>>> G; // 要素が {隣接点, 隣接点までの距離} の グラフ
int V, E;

vector<ll> dijkstra(int s) {
    vector<bool> fixed(V, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;

    vector<ll> dist(V, 2e9);

    dist[s] = 0;
    que.push({dist[s], s});

    while(!que.empty()) {
        int v = que.top().second;
        que.pop();

        if(fixed[v]) continue;

        fixed[v] = true;
        for(auto v2 : G[v]) {
            int next = v2.first, cost = v2.second;
            if(dist[next] > dist[v]+cost) {
                dist[next] = dist[v] + cost;
                que.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    cin >> V >> E;
    G.resize(V);
    for(int i=0; i<E; i++) {
        int s, t, d; cin >> s >> t >> d;
        s--; t--;
        G[s].push_back({t, d});
        G[t].push_back({s, d});
    }

    // 始点 0 からの最短距離を取得
    vector<ll> ans = dijkstra(0);
    for(int i=0; i<V; i++) {
        if(ans[i] != 2e9) cout << ans[i] << endl;
        else cout << -1 << endl;
    }
}