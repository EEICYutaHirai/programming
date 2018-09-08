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

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ans = true;
    if (b - a > d)
        ans = false;
    if (b - c > d)
        ans = false;
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}