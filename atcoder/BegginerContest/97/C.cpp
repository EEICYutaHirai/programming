/*
title:

url:

Kが５以下であることに注目
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
    string ans[k];
    //find min alpahbet(a, b, c...)
    int count = 0;

    char min_alp = 'a';
    while (true)
    {
        vector<int> min_index;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == min_alp)
            {
                min_index.push_back(i);
            }
        }
        if (!min_index.empty())
        {
            auto c = [](const string &a, const string b) {
                if (strcmp(a.c_str(), b.c_str()) >= 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            };
            priority_queue<string, vector<string>, decltype(c)> q(c);
            for (int i = 0; i < min_index.size(); i++)
            {
                cout << min_index[i] << endl;
                string tmp = "";
                for (int j = 0; j < 5; j++)
                {
                    tmp += s[min_index[i] + j];
                    q.push(tmp);
                }
            }
            while (!q.empty())
            {
                if (count == 0 || q.top() != ans[count - 1])
                {
                    ans[count] = q.top();
                    count++;
                }
                q.pop();
                if (count == k)
                {
                    cout << ans[k - 1] << endl;
                    return 0;
                }
            }
        }
        min_alp += 1;
    }
}