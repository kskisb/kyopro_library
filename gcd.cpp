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

int gcd(int a, int b) {
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main() {
}