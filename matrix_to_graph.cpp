#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int> > matrix, G;
vector<int> dx = {0, -1, 1, 0};
vector<int> dy = {-1, 0, 0, 1};
// 8方向の場合
// vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
// vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};

vector<vector<int>> matrix_to_graph(vector<vector<int>> matrix, int h, int w) {
    G.assign(h*w, vector<int>());
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            for(int k=0; k<4; k++) {
                if(i+dy[k] < 0 || i+dy[k] >= h || j+dx[k] < 0 || j+dx[k] >= w) continue;
                if(matrix[i+dy[k]][j+dx[k]] && matrix[i][j]) {
                    G[i*w+j].push_back((i+dy[k])*w+j+dx[k]);
                }
            }
        }
    }

    return G;
}

int main() {
    int w, h; cin >> w >> h;
    matrix.assign(h, vector<int>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> matrix[i][j];
        }
    }
    G = matrix_to_graph(matrix, h, w);
    visited.assign(w*h, true);
    for(int i=0; i<w*h; i++) if(matrix[i/w][i%w]) visited[i] = false;
}