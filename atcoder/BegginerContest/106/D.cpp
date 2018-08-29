/*
title:AtCoder Express 2

url:https://abc106.contest.atcoder.jp/tasks/abc106_d

1.vector<pair<Li, Ri>>をLiでソート
2.pi<=Li を二分検索
3.検索したものをRiでソート
4.Ri<=qi を二分検索

計算量 O(3M*logN)

cf lower_bound を、pairを使って比較するときには、keyもpairにする必要がある。
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

typedef pair<int, int> p_i;

vector<p_i> data;

int N, M, Q;

int main()
{
    scanf("%d %d %d", &N, &M, &Q);
    REP(i, M)
    {
        int Li, Ri;
        p_i p;
        scanf("%d %d", &Li, &Ri);
        p.first = Li - 1;
        p.second = Ri - 1;
        data.push_back(p);
    }

    //1. Liでソート
    sort(data.begin(), data.end());

    REP(i, Q)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        p--;
        q--;
        //pi<=Li を二分検索
        p_i p_bgn = make_pair(p, p);
        vector<p_i>::iterator lb = lower_bound(data.begin(), data.end(), p_bgn);
        vector<p_i> tmp;
        copy(lb, data.end(), tmp.begin());
        p_i p_end = make_pair();
    }
}