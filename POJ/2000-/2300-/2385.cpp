#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string.h>

using namespace std;

int dp[1001][32];

int main()
{
    int T, W;
    cin >> T >> W;
    int fall[T];
    memset(fall, 0, sizeof(fall));
    for (int i = 0; i < T; i++)
    {
        cin >> fall[i];
    }

    for (int n_change = 0; n_change <= W; n_change++)
    {
        dp[T - 1][n_change] = ((abs(n_change - fall[T - 1]) % 2 == 1) ? 1 : 0);
    }
    for (int time = T - 2; time >= 0; time--)
    {
        for (int n_change = 0; n_change <= W; n_change++)
        {
            dp[time][n_change] =
                ((abs(n_change - fall[time]) % 2 == 1) ? 1 : 0) +
                max(dp[time + 1][n_change], dp[time + 1][n_change + 1]);
        }
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
}