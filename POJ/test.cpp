#include <iostream>

using namespace std;

#define MAX 255

void simple_mul_chars(int *a, int n_a, int b, int *ans)
{
    //cin はけた上がりの数
    int cin = 0;
    int i;
    for (i = 0; i < n_a; i++)
    {
        int temp = a[i] * b + cin;
        ans[i] = temp % 10;
        cin = temp / 10;
    }
    //ans[i] = -1 を終端文字とする。
    ans[i] = -1;
}

int main()
{
    int a[MAX];
    a[0] = 5;
    a[1] = 3;
    a[2] = 1;
    int n_a = 3;
    int b = 4;
    int ans[MAX];
    simple_mul_chars(a, n_a, b, ans);
    int n_ans = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (ans[i] == -1)
        {
            n_ans = i;
            break;
        }
    }
    for (int i = 0; i < n_ans; i++)
    {
        cout << ans[n_ans - i - 1];
    }
}