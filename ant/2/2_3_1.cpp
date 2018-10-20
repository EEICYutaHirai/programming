/*
ant P.52
ナップザック問題

入力例
:
4
2 3
1 2
3 4
2 2
5
出力例
:
7

*/

/*
再帰で実装
int get_value(int N, int index, int rest_weight)
{
    int res;
    if (index == N - 1)
    {
        return 0;
    }
    else if (rest_weight < w[index])
    {
        //もう入らない
        res = get_value(N, index + 1, rest_weight);
    }
    else
    {
        res = MAX(get_value(N, index + 1, rest_weight), get_value(N, index + 1, rest_weight - w[index]) + v[index]);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int W;
    cin >> W;

    cout << get_value(N, 0, W) << endl;
}
*/

#include <iostream>

#define MAX(a, b) ((a) <= (b) ? (b) : (a))

using namespace std;

int w[255], v[255];
int dp[255][255];

int get_value(int N, int index, int rest_weight)
{
    int res;

    if (dp[index][rest_weight] >= 0)
    {
        return dp[index][rest_weight];
    }

    if (index == N - 1)
    {
        return 0;
    }
    else if (rest_weight < w[index])
    {
        //もう入らない
        res = get_value(N, index + 1, rest_weight);
    }
    else
    {
        res = MAX(get_value(N, index + 1, rest_weight), get_value(N, index + 1, rest_weight - w[index]) + v[index]);
    }
    return dp[index][rest_weight] = res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int W;
    cin >> W;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << get_value(N, 0, W) << endl;
}
