#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int fall[1001];
//[time][changeした回数]
int memo[1001][30];
int T;
int W;

int solve(int time, int n_change)
{
    if (memo[time][n_change] >= 0)
    {
        return memo[time][n_change];
    }
    if (time + 1 == T)
    {
        return memo[time][n_change] = ((abs(n_change - fall[time]) % 2 == 1) ? 1 : 0);
    }
    else
    {
        if (n_change < W)
        {
            return memo[time][n_change] =
                       (((abs(n_change - fall[time]) % 2 == 1) ? 1 : 0) + max(solve(time + 1, n_change), solve(time + 1, n_change + 1)));
        }
        else
        {
            return memo[time][n_change] =
                       (((abs(n_change - fall[time]) % 2 == 1) ? 1 : 0) + solve(time + 1, n_change));
        }
    }
}

int main()
{
    memset(memo, -1, sizeof(memo));
    cin >> T >> W;
    for (int i = 0; i < T; i++)
    {
        cin >> fall[i];
    }

    int ans;
    if (W > 0)
    {
        ans = max(solve(0, 0), solve(0, 1));
    }
    else
    {
        ans = solve(0, 0);
    }
    cout << ans << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 30; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
}