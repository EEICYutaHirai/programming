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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (gcd(a, b) == 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = 1; i < b; i++)
        {
            if ((a * i) % b == 1)
            {
                int syou = (a * i - 1) / b;
                cout << i << " 0 0 " << syou << endl;
                return 0;
            }
        }
    }
}