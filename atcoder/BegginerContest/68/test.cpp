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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    int data[N];
    rep(i, N)
    {
        cin >> data[i];
    }
    int count = 0;
    while ((*max_element(data, data + N)) >= N)
    {
        count++;
        rep(i, N)
        {
            data[i]++;
        }
        (*max_element(data, data + N)) -= N + 1;
    }
    cout << count << endl;
}