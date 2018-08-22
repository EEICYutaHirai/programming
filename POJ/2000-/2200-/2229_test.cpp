#include <iostream>
#include <string.h>

using namespace std;

int b_data[32][32][32][32][32][32];
int ans;

/*
31を入力すると、３１までの答えを出してくれる。このことから、法則を推測できる。
*/

void solve(int n0, int n1, int n2, int n3, int n4, int n5)
{
    if (b_data[n0][n1][n2][n3][n4][n5] == 0)
    {
        b_data[n0][n1][n2][n3][n4][n5] = 1;
        ans++;
    }
    if (n0 > 1)
    {
        solve(n0 - 2, n1 + 1, n2, n3, n4, n5);
    }
    if (n1 > 1)
    {
        solve(n0, n1 - 2, n2 + 1, n3, n4, n5);
    }
    if (n2 > 1)
    {
        solve(n0, n1, n2 - 2, n3 + 1, n4, n5);
    }
    if (n3 > 1)
    {
        solve(n0, n1, n2, n3 - 2, n4 + 1, n5);
    }
    if (n4 > 1)
    {
        solve(n0, n1, n2, n3, n4 - 2, n5 + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        ans = 0;
        solve(i, 0, 0, 0, 0, 0);
        cout << i << ": ";
        cout << ans << endl;
    }
}