#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;

vector<vector<ll> > dist;
int V, E;

void warshall_floyd(int n) {
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if((dist[i][k] < INF) && (dist[k][j] < INF)) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> V >> E;
    dist.assign(V, vector<ll>(V, INF));
    for(int i=0; i<E; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    for(int i=0; i<V; i++) dist[i][i] = 0;

    warshall_floyd(V);

    // 負閉路検出
    for(int i=0; i<V; i++) {
        if(dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(dist[i][j] != INF) cout << dist[i][j];
            else cout << "INF";
            if(j != V-1) cout << " ";
        }
        cout << endl;
    }
}