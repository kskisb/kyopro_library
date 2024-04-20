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



int main() {
    int n; cin >> n;
    vector<int> left(1000001, 0), right(1000001, 0);
    vector<int> p(1000001, 0);
    for(int i=0; i<n; i++) {
        int l, r; cin >> l >> r;
        left[l]++;
        right[r]++;
    }

    int tmp = 0;
    for(int i=0; i<=1000000; i++) {
        tmp += left[i];
        p[i] = tmp;
        tmp -= right[i];
    }
}