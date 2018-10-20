#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int fall[1001];
int memo[1001][2][30][2];
int T;

//tree->timeの時にどちらの木にいるか
//time ... 0~999
int solve(int time, int change, int W, int tree)
{
    if (memo[time][change][W][tree] >= 0)
    {
        return memo[time][change][W][tree];
    }
    if (change)
    {
        W--;
        if (tree == 1)
        {
            tree = 2;
        }
        else
        {
            tree = 1;
        }
    }
    if (time == T - 1)
    {
        return memo[time][change][W][tree] = fall[time] == tree ? 1 : 0;
    }
    if (W > 0)
    {
        return memo[time][change][W][tree] = MAX(solve(time + 1, false, W, tree), solve(time + 1, true, W, tree)) + (fall[time] == tree ? 1 : 0);
    }
    else
    {
        return memo[time][change][W][tree] = solve(time + 1, false, W, tree) + (fall[time] == tree ? 1 : 0);
    }
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int W;
    cin >> T >> W;
    for (int i = 0; i < T; i++)
    {
        cin >> fall[i];
    }
    int ans;
    if (W > 0)
    {
        ans = MAX(solve(0, 1, W, 1), solve(0, 0, W, 1));
    }
    else
    {
        ans = solve(0, 0, W, 1);
    }
    cout << ans << endl;
}