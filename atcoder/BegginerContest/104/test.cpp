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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
string abcs;

int main()
{
    cin >> abcs;
    int ans = 0;

    for (int i = 0; i < abcs.size(); i++)
    {
        if (abcs[i] == 'A' || abcs[i] == '?')
        {
            for (int j = i + 1; j < abcs.size(); j++)
            {
                if (abcs[j] == 'B' || abcs[j] == '?')
                {
                    for (int k = j + 1; k < abcs.size(); k++)
                    {
                        if (abcs[k] == 'C' || abcs[k] == '?')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}