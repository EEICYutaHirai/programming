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
    int N, M;
    cin >> N >> M;
    vector<vector<pint>> data(N, vector<pint>(0, pint(0, 0)));
    vector<string> ans(M, "");
    rep(i, M)
    {
        int city, year;
        cin >> city >> year;
        data[city - 1].push_back(pint(year, i));
    }
    rep(i, N)
    {
        sort(data[i].begin(), data[i].end());
    }
    rep(i, N)
    {
        string city_string = to_string(i + 1);
        while (city_string.size() != 6)
        {
            city_string = "0" + city_string;
        }
        rep(j, data[i].size())
        {
            string tmp = to_string(j + 1);
            while (tmp.size() != 6)
            {
                tmp = "0" + tmp;
            }
            ans[data[i][j].second] = city_string + tmp;
        }
    }
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
}