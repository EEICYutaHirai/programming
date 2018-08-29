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
#include <limits>
#include <utility>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

string data[20];

typedef pair<int, int> pair_int;
int W, H;
int ans;

pair_int find()
{
    pair_int p;
    REP(i, H)
    {
        REP(j, W)
        {
            if (data[i][j] == '@')
            {
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    return p;
}

bool is_valid(int i, int j)
{
    return 0 <= i && i < H && 0 <= j && j < W;
}

bool is_black(int i, int j)
{
    return data[i][j] == '.';
}

void solve(int i, int j)
{
    if (is_valid(i + 1, j) && is_black(i + 1, j))
    {
        ans++;
        data[i + 1][j] = 'y';
        solve(i + 1, j);
    }
    if (is_valid(i - 1, j) && is_black(i - 1, j))
    {
        ans++;
        data[i - 1][j] = 'y';
        solve(i - 1, j);
    }
    if (is_valid(i, j + 1) && is_black(i, j + 1))
    {
        ans++;
        data[i][j + 1] = 'y';
        solve(i, j + 1);
    }
    if (is_valid(i, j - 1) && is_black(i, j - 1))
    {
        ans++;
        data[i][j - 1] = 'y';
        solve(i, j - 1);
    }
}

int main()
{
    while (cin >> W)
    {
        if (W == 0)
        {
            return 0;
        }
        cin >> H;
        REP(i, H)
        {
            cin >> data[i];
        }

        pair_int p = find();

        ans = 1;
        solve(p.first, p.second);
        cout << ans << endl;
    }
}