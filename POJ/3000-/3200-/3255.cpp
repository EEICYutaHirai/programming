/*
title:Roadblocks

url:http://poj.org/problem?id=3255
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <limits>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

int main()
{
    int N, R;
    scanf("%d %d", &N, &R);

    int cost[N][N];
    for (int i = 0; i < N; i++)
    {
        fill(cost[i], cost[i] + N, INF);
    }
    REP(i, R)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    bool used[N];
    fill(used, used + N, false);
    int d[N];
    fill(d, d + N, INF);
    d[0] = 0;

    while (true)
    {
        int v = -1;
        REP(u, N)
        {
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if (v == -1)
            break;
        used[v] = true;
        REP(u, N)
        {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
    cout << d[N - 1] << endl;
}