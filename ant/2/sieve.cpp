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
#include <limits>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

int main()
{
    int N;
    cin >> N;

    bool sieve_is_prime[N + 1];
    fill(sieve_is_prime, sieve_is_prime + N, true);
    sieve_is_prime[0] = sieve_is_prime[1] = false;
    int ans = 0;
    for (int i = 2; i <= N; i++)
    {
        if (sieve_is_prime[i])
        {
            ans++;
            for (int j = 2 * i; j <= N; j += i)
            {
                sieve_is_prime[j] = false;
            }
        }
    }
    cout << ans << endl;
}