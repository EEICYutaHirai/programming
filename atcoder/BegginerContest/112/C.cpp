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
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int CX, CY, H;
    int N;
    cin >> N;
    int xdata[N], ydata[N], hdata[N];
    rep(i, N)
    {
        cin >> xdata[i] >> ydata[i] >> hdata[i];
    }
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            int h = 0;
            bool is_ans = true;
            rep(i, N)
            {
                if (hdata[i] != 0)
                {
                    h = abs(x - xdata[i]) + abs(y - ydata[i]) + hdata[i];
                    break;
                }
            }
            rep(i, N)
            {
                if (hdata[i] != MAX(0, h - abs(x - xdata[i]) - abs(y - ydata[i])))
                {
                    is_ans = false;
                    break;
                }
            }
            if (is_ans)
            {
                cout << x << " " << y << " " << h << endl;
                return 0;
            }
        }
    }

    return 0;
}