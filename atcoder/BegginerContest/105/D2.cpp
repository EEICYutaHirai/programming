/*
title:D - Candy Distribution

url:https://abc105.contest.atcoder.jp/tasks/abc105_d

方針:
A_l + ... A_r
にひつようなパラメーターはlとrのみなので、累積和を用いることで計算量を減らす。
また、すべてのl, rを累積和に対しててきようしていたのでは、計算量がO(N^2)となり、計算が間に合わない。
知りたい情報は,(l, r)のうち、Mで割り切れるかどうかである。知りたい情報量が少ないのでもっと少ない計算量で
答えを求めることができるのではないかと考える。
じっさいにMを法として、各累積和のうちあまりが同じものの数を考える。
例えばあまり1のものが５個あれば、5C2とおりの条件を満たす(l, r)があるはずである。
これを利用して答えを求める。
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
typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    //元のデータ
    int original_data[N + 1];
    for (int i = 1; i <= N; i++)
    {
        //cin >> original_data[i];
        original_data[i] = rand();
    }

    //同じ余りのものを記録しておく
    int *mod = (ll *)malloc(sizeof(ll) * M);
    memset(mod, 0, sizeof(mod));
    mod[0]++;

    //累積和.indexは１つずつずらしておく
    int acc[N + 1];
    memset(acc, 0, sizeof(acc));
    acc[0] = 0;

    bool *used = (bool *)malloc(sizeof(bool) * M);
    vector<ll> which_to_use;
    for (int i = 1; i <= N; i++)
    {
        acc[i] = acc[i - 1] + original_data[i];
        int tmp = acc[i] % M;
        mod[tmp]++;
        if (!used[tmp])
        {
            used[tmp] = true;
            which_to_use.push_back(tmp);
        }
    }

    ll ans = 0;
    //すべてのMに対して走査すると、とんでもなく時間がかかる
    //したがって、あらかじめどの余りの時に計算が必要か記録しておく
    /*
    for (int i = 0; i < M; i++)
    {
        ans += mod[i] * (mod[i] - 1) / 2;
    }
    */
    for (int i = 0; i < which_to_use.size(); i++)
    {
        ans += mod[which_to_use[i]] * (mod[which_to_use[i]] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}