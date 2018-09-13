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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int data[3] = {1, 2, 3};
    (*min_element(data, data + 3))++;
    for (int i = 0; i < 3; i++)
    {
        cout << data[i] << endl;
    }
}