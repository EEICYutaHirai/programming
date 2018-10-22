/*
title:

url:

cf lower_bound を、pairを使って比較するときには、keyもpairにする必要がある。
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

typedef pair<int, int> p_i;

vector<p_i> data;

bool test_func(const p_i &a, const p_i &b)
{
    return a.second > b.second;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        p_i p;
        p.first = 10 - i;
        p.second = 10 - i;
        data[i] = p;
    }
    sort(data.begin(), data.end());
    p_i p = make_pair(8, 0);
    lower_bound(data.begin(), data.end(), p);
    cout << (p < 3) << endl;
    //lower_bound(data.begin(), data.end(), 8, [](const p_i &a, const p_i &b) { return a.first < b.first; });
    //cout << *it << endl;
}