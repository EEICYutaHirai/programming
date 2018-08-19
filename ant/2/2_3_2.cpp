#include <iostream>
#include <string>

#define MAX(a, b) ((a) >= b ? (a) : (b))

using namespace std;
int max_index_s;
int max_index_t;
int dp[255][255];
string s, t;

int main()
{
    cin >> max_index_s >> max_index_t;
    cin >> s >> t;
    for (int i = 1; i <= max_index_s; i++)
    {
        for (int j = 1; j <= max_index_t; j++)
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
            else
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
    }
    cout << dp[max_index_s][max_index_t] << endl;
}