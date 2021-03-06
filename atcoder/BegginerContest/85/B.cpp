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
    int n;
    cin >> n;
    int ans = 0;
    vector<int> data;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (data.end() != find(data.begin(), data.end(), a))
        {
            continue;
        }
        else
        {
            data.push_back(a);
            ans++;
        }
    }
    cout << ans << endl;
}