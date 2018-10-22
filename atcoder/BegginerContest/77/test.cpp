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
#define MAX 15

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    for (int k = 2; k <= 100; k++)
    {
        int n = k;
        vector<int> d;
        d.push_back(1);
        bool looped = false;
        for (int i = 1; i >= 0; i++)
        {
            int tmp;
            tmp = (d[i - 1] * 10) % n;
            if (find(d.begin(), d.end(), tmp) != d.end())
            {
                looped = true;
            }
            d.push_back(tmp);
            if (looped && i > MAX)
            {
                break;
            }
        }
        int tmp_k = n;
        while (tmp_k % 2 == 0)
        {
            tmp_k /= 2;
        }
        while (tmp_k % 5 == 0)
        {
            tmp_k /= 5;
        }
        if (tmp_k == 1)
        {
            cout << 1 << endl;
        }

        int ans = 0;
        sort(d.begin(), d.end(), greater<int>());
        for (int i = 0; i < d.size(); i++)
        {
            ans += n / d[i];
            n %= d[i];
            if (n == 0)
            {
                break;
            }
        }
        cout << k << "\t";
        cout << ans << endl;
    }
    return 0;
}