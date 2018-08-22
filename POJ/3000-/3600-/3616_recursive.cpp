#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int N, M, R;
pair<pair<int, int>, int> milk_time[1001];
int dp[1000000 + 1][1000];

// 0 <= index < M
int solve(int time, int index)
{
    if (time >= N || index == M)
    {
        return dp[time][index] = 0;
    }
    else if (time <= milk_time[index].first.first)
    {
        return dp[time][index] = max(solve(time, index + 1), milk_time[index].second + solve(milk_time[index].first.second + R, index + 1));
    }
    else
    {
        return dp[time][index] = solve(time, index + 1);
    }
}

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++)
    {
        cin >>
            milk_time[i].first.first >>
            milk_time[i].first.second >>
            milk_time[i].second;
    }
    sort(milk_time, milk_time + M);
    cout << solve(0, 0) << endl;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}