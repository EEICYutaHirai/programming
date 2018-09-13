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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k == 0)
    {
        k++;
    }
    for (int i = k + 1; i <= n; i++)
    {
        for (int j = k; j <= i - 1; j++)
        {
            ans += 1 + (n - i) / j;
        }
    }
    cout << ans << endl;
}