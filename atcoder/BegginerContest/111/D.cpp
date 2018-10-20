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
    cin >> N;
    pint data[N];
    int sum[N];
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        data[i] = pint(a, b);
        sum[i] = a + b;
    }
    int m;
    rep(i, N)
    {
        if (abs(sum[i] - sum[0]) % 2 != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (abs(sum[0] % 2) == 0)
    {
        m = 40;
    }
    else
    {
        m = 39;
    }

    cout << m << endl;

    rep(i, m)
    {
        cout << 1 << " ";
    }
    cout << endl;

    rep(i, N)
    {
        int tmp_sum = 0;
        if (data[i].first > 0)
        {
            rep(j, abs(data[i].first))
            {
                cout << "R"
                     << " ";
            }
        }
        else
        {
            rep(j, abs(data[i].first))
            {
                cout << "L"
                     << " ";
            }
        }
        if (data[i].second > 0)
        {
            rep(j, abs(data[i].second))
            {
                cout << "U"
                     << " ";
            }
        }
        else
        {
            rep(j, abs(data[i].second))
            {
                cout << "D"
                     << " ";
            }
        }
        rep(j, m - abs(data[i].first) - abs(data[i].second))
        {
            if (j % 2 == 0)
            {
                cout << "R"
                     << " ";
            }
            else
            {
                cout << "L"
                     << " ";
            }
        }
        cout << endl;
    }
    return 0;
}