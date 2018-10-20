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
    int max_n = 100000;
    pint n_even[100001];
    pint n_odd[100001];
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0)
        {
            n_even[tmp].first++;
            n_even[tmp].second = tmp;
        }
        else
        {
            n_odd[tmp].first++;
            n_odd[tmp].second = tmp;
        }
    }

    sort(n_even, n_even + 100001, greater<pint>());
    sort(n_odd, n_odd + 100001, greater<pint>());

    int max_odd = n_odd[0].first;
    int max_even = n_even[0].first;

    if (n_odd[0].second == n_even[0].second)
    {
        if (n_odd[1].first > n_even[1].first)
        {
            max_odd = n_odd[1].first;
        }
        else
        {
            max_even = n_even[1].first;
        }
    }
    int ans = N - max_even - max_odd;
    cout << ans << endl;
    return 0;
}