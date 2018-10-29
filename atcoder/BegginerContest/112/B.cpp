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
    int N, T;
    cin >> N >> T;
    vector<pint> data(N, pint(0, 0));
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        data[i] = pint(a, b);
    }
    sort(data.begin(), data.end());
    rep(i, N)
    {
        if (data[i].second <= T)
        {
            cout << data[i].first << endl;
            return 0;
        }
    }
    cout << "TLE" << endl;
    return 0;
}