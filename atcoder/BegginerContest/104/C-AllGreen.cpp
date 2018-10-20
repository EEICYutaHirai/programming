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

int D, G;
int p[11], c[11];

//戻り値はGをこえるのにひつような最小の問題数
//index
int solve(int index, int score, bool incomp)
{
    if (score >= G)
    {
        return 0;
    }
    else if (index == D)
    {
        //どうがんばっても無理だった時
        return INF;
    }
    else
    {
        //indexをすべて説くか、中途半端に説くか、まったく解かないかの三種類
        //すでに中途半端に説かれた奴がある->まったくとかないか、すべてとくか
        if (incomp)
        {
            return min(p[index] + solve(index + 1, (index + 1) * p[index] * 100 + c[index] + score, incomp),
                       solve(index + 1, score, incomp));
        }
        else
        {
            int minimum = min(p[index] + solve(index + 1, (index + 1) * p[index] * 100 + c[index] + score, incomp),
                              solve(index + 1, score, incomp));
            int tmp;
            for (int i = 1; i < p[index]; i++)
            {
                tmp = i + solve(index + 1, (index + 1) * i * 100 + score, true);
                if (tmp < minimum)
                    minimum = tmp;
            }
            return minimum;
        }
    }
}

int main()
{
    cin >> D >> G;
    for (int i = 0; i < D; i++)
    {
        cin >> p[i] >> c[i];
    }
    cout << solve(0, 0, false) << endl;
}