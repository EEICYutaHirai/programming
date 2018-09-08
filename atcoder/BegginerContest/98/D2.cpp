/*
title:D - Xor Sum 2
 
url:
 
方針:xorを累積和で表したい。
ここで,じっさいにxorは
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    int sum[n + 1] = {};
    int xsum[n + 1] = {};
    //(l, r) = sum[r] - sum[l-1]
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum[i + 1] = sum[i] + tmp;
        xsum[i + 1] = xsum[i] ^ tmp;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if ((sum[j] - sum[i - 1]) == (xsum[j] ^ xsum[i - 1]))
            {
                cout << "l:" << i << " r:" << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}