#include <iostream>

using namespace std;

typedef long long ll;

ll memo[1000001];
ll nine = 1000000000;
ll ten = nine * 10;

/*
教訓
実行時間がギリギリな時は、オーダ的に間に合っていても、
無駄な条件分岐が多いと、うまくいかない場合がある。
*/

int main()
{
    int N;
    cin >> N;
    memset(memo, -1, sizeof(memo));
    memo[1] = 1;
    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans;
    for (int i = 2; i <= N + 2; i = i + 2)
    {
        ll p =
            (memo[i - 1] + memo[i / 2]) % nine;
        memo[i] = p;
        memo[i + 1] = p;
    }
    cout << memo[N] << endl;
}