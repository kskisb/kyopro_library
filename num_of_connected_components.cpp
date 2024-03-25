#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int> > G;

void dfs(int v) {
    visited[v] = true;
    for(auto next : G[v]) {
        if(visited[next]) continue;
        dfs(next);
    }
}

int main() {
    // グラフの入力など

    visited.assign(N, false);
    int cnt = 0;
    for(int i=0; i<h*w; i++) {
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl; // cnt が連結成分の個数
}