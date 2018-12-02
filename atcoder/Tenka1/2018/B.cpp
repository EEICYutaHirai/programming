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
    int A, B, K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; i++)
    {
        if (i % 2 == 0)
        {
            if (A % 2 == 1)
            {
                A--;
                B += A / 2;
                A /= 2;
            }
            else
            {
                B += A / 2;
                A /= 2;
            }
        }
        else
        {
            if (B % 2 == 1)
            {
                B--;
                A += B / 2;
                B /= 2;
            }
            else
            {
                A += B / 2;
                B /= 2;
            }
        }
    }
    cout << A << " " << B << endl;
    return 0;
}