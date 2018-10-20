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
    int N;
    cin >> N;
    for (int i = 1; i <= 9; i++)
    {
        int tmp = i + 10 * i + 100 * i;
        if (N <= tmp)
        {
            cout << tmp << endl;
            return 0;
        }
    }
    return 0;
}