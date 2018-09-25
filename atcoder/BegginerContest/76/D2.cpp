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
    vector<double> t, v;
    rep(i, n)
    {
        double tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    rep(i, n)
    {
        double tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(0.);

    double now_speed = 0.;
    double ans = 0.;
    rep(i, n)
    {
        double vmax = min(v[i], (now_speed + t[i] + v[i + 1]) / 2.); //6
        double start_dec = t[i] - max(0., vmax - v[i + 1]);          //8
        ans += 0.5 * (now_speed + vmax) * (vmax - now_speed);
        ans += vmax * max(0., start_dec - vmax + now_speed);       //2*6
        ans += 0.5 * (vmax + v[i + 1]) * max(0., vmax - v[i + 1]); //0.5*6*
        now_speed = min(vmax, v[i + 1]);
    }
    cout << ans << endl;
}