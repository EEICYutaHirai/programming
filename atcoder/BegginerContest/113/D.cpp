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

vector<int> f;

void set_f(int W)
{
    f.push_back(1);
    f.push_back(2);
    f.push_back(3);
    while (f.size() - 1 <= W)
    {
        f.push_back((f[f.size() - 1] + f[f.size() - 2]) % INF);
    }
}

int get_f(int index)
{
    if (index < 0)
        return 1;
    return f[index];
}

signed main()
{
    int H, W, K;
    cin >> H >> W >> K;
    int data[W + 2][H + 1];
    set_f(W);
    memset(data, 0, sizeof(data));
    data[1][0] = 1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            data[j][i] %= INF;
            data[j - 1][i + 1] += (data[j][i] * get_f(j - 3) % INF) * get_f(W - j - 1) % INF;
            data[j][i + 1] += data[j][i] * get_f(j - 2) * get_f(W - j - 1) % INF;
            data[j + 1][i + 1] += data[j][i] * get_f(j - 2) * get_f(W - j - 2) % INF;
            data[j - 1][i + 1] %= INF;
            data[j][i + 1] %= INF;
            data[j + 1][i + 1] %= INF;
        }
    }
    cout << data[K][H] % INF << endl;
}