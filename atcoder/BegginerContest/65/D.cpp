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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    pint xdata[N];
    pint ydata[N];
    rep(i, N)
    {
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        xdata[i] = pint(tmp_x, tmp_y);
        ydata[i] = pint(tmp_y, tmp_x);
    }

    sort(xdata, xdata + N);
    sort(ydata, ydata + N);

    int xans, yans;
    xans = yans = 0;
    rep(i, N - 1)
    {
        xans += min(abs(xdata[i].first - xdata[i + 1].first), abs(xdata[i].second - xdata[i + 1].second));
    }
    rep(i, N - 1)
    {
        yans += min(abs(ydata[i].first - ydata[i + 1].first), abs(ydata[i].second - ydata[i + 1].second));
    }

    cout << min(xans, yans) << endl;
}