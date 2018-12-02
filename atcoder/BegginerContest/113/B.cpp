/*
title:

url:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <utility>
#include <cstring>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int N;
    int T, A;
    cin >> N;
    cin >> T >> A;
    vector<pair<double, int>> data(N, pair<double, int>(0, 0));
    rep(i, N)
    {
        double tmp;
        cin >> tmp;
        data[i] = pair<double, int>(abs(double(A) - (double(T) - tmp * 0.006)), i);
    }
    sort(data.begin(), data.end());
    cout << data[0].second + 1 << endl;
}