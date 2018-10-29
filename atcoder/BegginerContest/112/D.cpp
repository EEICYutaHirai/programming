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
    int N, M;
    cin >> N >> M;
    int max_n;
    if (100000 > M / N)
    {
        max_n = 100000;
    }
    else
    {
        max_n = M / N;
    }
    int ans = 1;
    for (int i = max_n; i >= 1; i--)
    {
        if (M % i == 0 && i * N <= M)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}