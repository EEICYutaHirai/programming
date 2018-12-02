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

    vector<int> vprime;
    vprime.push_back(2);
    vprime.push_back(3);
    vprime.push_back(5);
    vprime.push_back(7);
    vprime.push_back(11);
    vprime.push_back(13);
    vprime.push_back(17);
    vprime.push_back(19);
    vprime.push_back(23);
    vprime.push_back(29);
    vprime.push_back(31);
    vprime.push_back(37);
    vprime.push_back(41);
    vprime.push_back(43);
    vprime.push_back(47);

    vector<int> n_prime_factor(vprime.size(), 0);
    for (int i = 0; i < vprime.size(); i++)
    {
        int tmp = vprime[i];
        while (tmp <= N)
        {
            n_prime_factor[i] += (N / tmp);
            tmp = vprime[i] * tmp;
        }
    }

    int ans = 0;
    //(2, 24)
    for (int i = 0; i < vprime.size(); i++)
    {
        for (int j = 0; j < vprime.size(); j++)
        {
            if (i != j && n_prime_factor[i] >= 2 && n_prime_factor[j] >= 24)
                ans++;
        }
    }

    //(4, 14)
    for (int i = 0; i < vprime.size(); i++)
    {
        for (int j = 0; j < vprime.size(); j++)
        {
            if (i != j && n_prime_factor[i] >= 4 && n_prime_factor[j] >= 14)
                ans++;
        }
    }

    //4,4,2
    for (int i = 0; i < vprime.size(); i++)
    {
        for (int j = i + 1; j < vprime.size(); j++)
        {
            for (int l = 0; l < vprime.size(); l++)
            {
                if (i != j && i != l && j != l)
                {
                    if (n_prime_factor[i] >= 4 && n_prime_factor[j] >= 4 && n_prime_factor[l] >= 2)
                    {
                        ans++;
                    }
                }
            }
        }
    }

    //74

    for (int i = 0; i < vprime.size(); i++)
    {
        if (n_prime_factor[i] >= 74)
        {
            ans++;
        }
    }

    cout << ans << endl;
}