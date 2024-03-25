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

int N = 4;

// vector A を出力する関数
void print(const vector<int> &A) {
    cout << "[";
    for(int i=0; i<A.size(); i++) {
        if(i > 0) cout << ", ";
        cout << A[i];
    }
    cout << "]" << endl;
}

// 0, 1 からなる長さ N の数列 A を列挙
void rec(vector<int> &A) {
    // 終了条件 : A のサイズが N に達したら終了
    if(A.size() == N) {
        print(A);
        return;
    }

    for(int v=0; v<2; v++) {
        A.push_back(v);
        rec(A);
        A.pop_back();
    }
}

int main() {
    vector<int> A;
    rec(A);
}