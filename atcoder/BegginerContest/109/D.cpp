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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int h, w;
int coin[500][500];
bool used[500][500];

int main()
{
    cin >> h >> w;
    int nodd = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> coin[i][j];
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
                }
    }
}