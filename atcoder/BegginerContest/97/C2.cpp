/*
title:

url:

Kが５以下であることに注目
教訓
最初の方針よりも単純にかけた
まずは計算量を試算することが大事。あと、メモリ使用量
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
    string s;
    int k;
    cin >> s >> k;
    //find min alpahbet(a, b, c...)

    priority_queue<string, vector<string>, greater<string>> q;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        string tmp = "";
        for (unsigned int j = 0; j < 5 && j + i < s.size(); j++)
        {
            tmp = tmp + s[i + j];
            q.push(tmp);
        }
    }
    string ans;
    for (int i = 0; i < k; i++)
    {
        ans = q.top();
        while ((!q.empty()) && q.top() == ans)
        {
            q.pop();
        }
    }
    cout << ans << endl;
}