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
    vector<string> vstring[9];
    int ans = 0;

    vstring[0].push_back("7");
    vstring[0].push_back("3");
    vstring[0].push_back("5");

    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < vstring[i - 1].size(); j++)
        {
            vstring[i].push_back(vstring[i - 1][j] + "3");
            vstring[i].push_back(vstring[i - 1][j] + "5");
            vstring[i].push_back(vstring[i - 1][j] + "7");
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < vstring[i].size(); j++)
        {
            if (vstring[i][j].find("3") == std::string::npos)
            {
                continue;
            }
            if (vstring[i][j].find("5") == std::string::npos)
            {
                continue;
            }
            if (vstring[i][j].find("7") == std::string::npos)
            {
                continue;
            }
            if (atoi(vstring[i][j].c_str()) <= N)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}