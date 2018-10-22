//POJ, compile error

#include <iostream>
#include <utility>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000000 + 1][1001];

int main()
{
    int N, M, R;
    pair<pair<int, int>, int> milk_time[1001];
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++)
    {
        cin >>
            milk_time[i].first.first >>
            milk_time[i].first.second >>
            milk_time[i].second;
    }
    sort(milk_time, milk_time + M);
    for (int index = M; index >= 0; index--)
    {
        for (int time = 0; time <= N; time++)
        {
            if (time <= milk_time[index].first.first)
                dp[time][index] = max(dp[time][index + 1], milk_time[index].second + dp[milk_time[index].first.second + R][index + 1]);
            else
                dp[time][index] = dp[time][index + 1];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}