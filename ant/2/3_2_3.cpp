#include <iostream>

using namespace std;

int dp[255][255];

int main()
{
    int n, W;
    cin >> n;
    int w[n], v[n];
    int min_weight;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        if (i == 0)
        {
            min_weight = w[0];
        }
        else if (w[i] < min_weight)
        {
            min_weight = w[i];
        }
    }
    cin >> W;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W / min_weight; j++)
        {
                }
    }
}