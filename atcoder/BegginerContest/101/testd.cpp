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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> p_i;

int get_sum_digit(int n)
{
    int res = 0;
    int ten = 10;
    while (n > 0)
    {
        int tmp = (n % 10);
        res += tmp;
        n -= tmp;
        n /= 10;
        ten *= 10;
    }
    return res;
}

double get_sunuke(int n)
{
    return (double)(n) / (double)(get_sum_digit(n));
}

bool is_sunuke(int n, int max)
{
    double sunuke = get_sunuke(n);
    for (int i = n + 1; i <= max; i++)
    {
        if (sunuke > get_sunuke(i))
            return false;
    }
    return true;
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 100000; i <= n; i++)
    {
        if (is_sunuke(i, 10000000))
            cout << i << ": " << get_sunuke(i) << endl;
    }
}