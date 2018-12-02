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
    int ans = INF;
    for (int i = 0; i + 2 < S.size(); i++)
    {

        string stmp = "";
        stmp.push_back(S[i]);
        stmp.push_back(S[i + 1]);
        stmp.push_back(S[i + 2]);
        int tmp = atoi(stmp.c_str());
        if (abs(tmp - 753) < ans)
        {
            ans = abs(tmp - 753);
        }
    }
    cout << ans << endl;
}