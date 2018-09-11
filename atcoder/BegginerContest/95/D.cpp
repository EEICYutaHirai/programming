/*
title:

url:

方針: どこでUターンするかどうかを考える。
尺取り法を用いて計算する
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n, c;
    cin >> n >> c;
    vector<pint> data;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        data.push_back(pint(a, b));
    }
    sort(data.begin(), data.end());

    int r = 0;
    int pre = 0;
    bool used[data.size];
    for (int i = 0; i < data.size(); i++)
    {
        int tmp = data[i].second - (data[i].first - pre);
        if (tmp > 0)
        {
            r += data[i].second - (data[i].first - pre);
            pre = data[i].first;
            used[i] = true;
        }
        else
        {
            used[i] = false;
        }
    }
    int ans = r;
    for (int i = data.size() - 1; i > 0; i--)
    {
        r += (data[i].first - data[i - 1].first);
        r -= c - (data[i].first - data[i - 1].first);
        ans = max(ans, r);
    }

    for (int i = 0; i < data.size(); i++)
    {
        data[i].first = c - data[i].first;
    }
    sort(data.begin(), data.end());
    int l = 0;
    pre = 0;
    for (int i = 0; i < data.size(); i++)
    {
        int tmp = data[i].second - (data[i].first - pre);
        if (tmp > 0)
        {
            l += tmp;
            pre = data[i].first;
        }
    }
    ans = max(ans, l);
    for (int i = data.size() - 1; i > 0; i--)
    {
        l += (data[i].first - data[i - 1].first);
        l -= c - (data[i].first - data[i - 1].first);
        ans = max(ans, l);
    }
    cout << ans << endl;
}