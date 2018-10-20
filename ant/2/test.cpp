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
#include <limits>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

struct Test
{
    int operator+(int i)
    {
        return 2 + i;
    }
};

int main()
{
    Test test;
    cout << test + 3 << endl;
}