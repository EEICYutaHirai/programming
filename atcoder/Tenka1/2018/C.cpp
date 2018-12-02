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
    int ans1 = 0;
    int ans2 = 0;
    int front, back;
    sort(data, data + N);
    int count = 0;
    front = data[0];
    back = data[N - 1];
    count = 2;
    ans1 += abs(front - back);
    int next_f_index = 1;
    int next_b_index = N - 2;
    while (count < N)
    {
        if (count % 2 == 0)
        {
            int abs_back = abs(back - data[next_f_index]);
            int abs_front = abs(front - data[next_f_index]);
            if (abs_back == abs_front)
            {
                if (back - data[next_f_index] >= 0)
                {
                    ans1 += abs_back;
                    back = data[next_f_index];
                }
                else
                {
                    front = data[next_f_index];
                    ans1 += abs_front;
                }
            }
            else if (abs_back > abs_front)
            {
                ans1 += abs_back;
                back = data[next_f_index];
            }
            else
            {
                ans1 += abs_front;
                front = data[next_f_index];
            }
            next_f_index++;
        }
        else
        {
            int abs_back = abs(back - data[next_b_index]);
            int abs_front = abs(front - data[next_b_index]);
            if (abs_back == abs_front)
            {
                if (back - data[next_b_index] <= 0)
                {
                    ans1 += abs_back;
                    back = data[next_b_index];
                }
                else
                {
                    front = data[next_b_index];
                    ans1 += abs_front;
                }
            }
            else if (abs_back > abs_front)
            {
                ans1 += abs_back;
                back = data[next_b_index];
            }
            else
            {
                ans1 += abs_front;
                front = data[next_b_index];
            }
            next_b_index--;
        }
        count++;
    }

    front = data[0];
    back = data[N - 1];
    count = 2;
    ans2 += abs(front - back);
    next_f_index = 1;
    next_b_index = N - 2;
    while (count < N)
    {
        if (count % 2 == 1)
        {
            int abs_back = abs(back - data[next_f_index]);
            int abs_front = abs(front - data[next_f_index]);
            if (abs_back == abs_front)
            {
                if (back - data[next_f_index] >= 0)
                {
                    ans2 += abs_back;
                    back = data[next_f_index];
                }
                else
                {
                    front = data[next_f_index];
                    ans2 += abs_front;
                }
            }
            else if (abs_back > abs_front)
            {
                ans2 += abs_back;
                back = data[next_f_index];
            }
            else
            {
                ans2 += abs_front;
                front = data[next_f_index];
            }
            next_f_index++;
        }
        else
        {
            int abs_back = abs(back - data[next_b_index]);
            int abs_front = abs(front - data[next_b_index]);
            if (abs_back == abs_front)
            {
                if (back - data[next_b_index] <= 0)
                {
                    ans2 += abs_back;
                    back = data[next_b_index];
                }
                else
                {
                    front = data[next_b_index];
                    ans2 += abs_front;
                }
            }
            else if (abs_back > abs_front)
            {
                ans2 += abs_back;
                back = data[next_b_index];
            }
            else
            {
                ans2 += abs_front;
                front = data[next_b_index];
            }
            next_b_index--;
        }
        count++;
    }
    if (ans1 > ans2)
    {
        cout << ans1 << endl;
    }
    else
    {
        cout << ans2 << endl;
    }
    return 0;
}