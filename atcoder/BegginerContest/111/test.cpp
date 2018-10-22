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
    cout << 100000 << endl;
    for (int i = 1; i <= 100000; i++)
    {
        if (i % 2 == 0)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 3 << " ";
        }
    }
    cout << endl;
    return 0;
}