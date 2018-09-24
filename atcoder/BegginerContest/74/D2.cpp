/*
title:

url:

むずい
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

int N;
int data[300][300];
int d[300];

bool bellman(int start)
{
    fill(d, d + N, INF);
    d[start] = 0;
    priority_queue<pint, vector<pint>, greater<pint>> q;
    q.push(pint(0, start));
    while (q.size())
    {
        pint p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        rep(i, N)
        {
            if (d[i] > d[v] + data[v][i])
            {
                d[i] = d[v] + data[v][i];
                q.push(pint(d[i], i));
            }
        }
    }
    rep(j, N)
    {
        if (data[start][j] != d[j])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    cin >> N;
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> data[i][j];
        }
    }

    rep(i, N)
    {
        if (!bellman(i))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    bool has_road[N][N];
    rep(i, N)
    {
        fill(has_road[i], has_road[i] + N, true);
    }
    rep(i, N)
    {
        rep(j, N)
        {
            rep(k, N)
            {
                if (i != j && j != k && k != i)
                {
                    bool nec = true;
                    if (data[i][j] >= data[i][k] + data[k][j])
                    {
                        nec = false;
                    }
                    if (!nec)
                    {
                        has_road[i][j] = false;
                        has_road[j][i] = false;
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(i, N)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (has_road[i][j])
            {
                ans += data[i][j];
            }
        }
    }
    cout << ans << endl;
}