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
    vector<string> data;
    data.push_back("BPPPB");

    for (int i = 0; i < 4; i++)
    {
        data.push_back("B" + data[i] + "P" + data[i] + "B");
    }

    rep(i, data.size())
    {

        cout << data[i] << endl;
    }
    int ans = 0;
    for (int i = 0; i < data[3].size(); i++)
    {
        if (data[3][i] == 'P')
            ans++;
        cout << ans << " ";
    }
}