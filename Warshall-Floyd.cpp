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
int N, M;

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
    cin >> N >> M;
    dist.assign(N, vector<ll>(N, INF));
    for(int i=0; i<M; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    for(int i=0; i<N; i++) dist[i][i] = 0;

    warshall_floyd(N);

    // 負閉路検出
    for(int i=0; i<N; i++) {
        if(dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(dist[i][j] != INF) cout << dist[i][j];
            else cout << "INF";
            if(j != N-1) cout << " ";
        }
        cout << endl;
    }
}