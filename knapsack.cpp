#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
using namespace std;
using ll=long long;

int N, W;
vector<int> w, v;

int rec(int n, int sw, int sv) {
    if(n == N) return sv;

    int result = 0;
    int score = rec(n+1, sw, sv);
    result = max(result, score);

    if(sw + w[n] <= W) {
        score = rec(n+1, sw+w[n], sv+v[n]);
        result = max(result, score);
    }

    return result;
}

int main() {
    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    for(auto& wi : w) cin >> wi;
    for(auto& vi : v) cin >> vi;
    cout << rec(0, 0, 0) << endl;
}