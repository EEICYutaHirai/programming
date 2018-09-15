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

template <class T>
vector<vector<T>> Imos2D(const vector<vector<T>> &a)
{
    int h = a.size();
    int w = a[0].size();
    vector<vector<T>> s(h + 1, vector<T>(w + 1, 0));
    rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
    return s;
}

//元のでーたで(i-1,j-1)~(i+h-1, j+w-1)を頂点に持つ長方形のなかノ和
template <class T>
int sum(const std::vector<std::vector<T>> &s, int i, int j, int h, int w)
{
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}

int main()
{
    vector<vector<int>> v(100, vector<int>(100, 1));
    auto imos = Imos2D(v);
    cout << sum(imos, 3, 3, 2, 3) << endl;
    cout << "Yes" << endl;
}