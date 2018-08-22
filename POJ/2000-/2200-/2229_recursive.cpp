#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int N;

typedef long long ll;

ll nine = 1000000000;

ll ten = nine * 10;

ll *memo = (ll *)malloc(sizeof(ll) * 1000000);

/*
今回の問題の条件では、再帰が深すぎるためにsegmentation fault が起きてしまう。
別の方法を考える必要がある。
*/
ll solve(int n)
{
    if (memo[n] >= 0)
    {
        return memo[n];
    }
    if (n == 1)
    {
        return memo[1] = 1;
    }
    else if (n % 2 == 0)
    {
        return memo[n] = solve(n + 1);
    }
    else
    {
        return memo[n] =
                   ((n % 4) == 1 ? solve((n + 1) / 2) + solve(n - 2) : solve((n - 1) / 2) + solve(n - 2)) % ten;
    }
}

int main()
{
    cin >> N;
    memset(memo, -1, sizeof(int) * 1000000);
    cout << solve(N) % nine << endl;
}