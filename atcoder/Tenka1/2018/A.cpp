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
    string S;
    cin >> S;
    if (S.size() == 2)
    {
        cout << S << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < S.size(); i++)
        {
            cout << S[S.size() - 1 - i];
        }
        cout << endl;
        return 0;
    }
    return 0;
}