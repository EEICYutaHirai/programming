#include <iostream>
#include <cstring>
using namespace std;
int la;

void gaocheng(int *a, int *b, int lb)
{
    int i, j;
    //la=string(a).length();
    //lb=string(b).length();
    int *s = new int[200];
    for (i = 1; i <= la + lb; i++)
        s[i] = 0;
    for (i = 1; i <= la; i++)
        for (j = 1; j <= lb; j++)
            s[i + j - 1] += a[i] * b[j];
    la = la + lb;
    for (i = 1; i <= la; i++)
    {
        s[i + 1] += s[i] / 10;
        a[i] = s[i] % 10;
    }
    while (a[la] == 0)
        la--;
    delete[] s;
}

int main()
{
    char m[30];
    int n, l, j, i, k, lb, f, p, u;
    while (cin >> m >> n)
    {
        int a[200] = {0, 0}, b[30] = {0, 0};
        k = 0;
        l = string(m).length();
        la = 1;
        lb = 1;
        f = 1;
        p = 0;
        u = 0;
        for (i = 0; i < l; i++)
            if (m[i] == '0' || m[i] == '.')
                k = 1;
            else
            {
                k = 0;
                break;
            }
        for (i = 0; i < l; i++)
        {
            if (m[0] == '.')
                f = 0;
            if (m[i] == '0')
                u++;
            else
                break;
        }

        if (k == 1)
            cout << '0';
        if (n == 0 && k == 0)
        {
            cout << '1';
            k = 1;
        }

        if (k == 0)
        {
            for (i = l - 1; i >= u; i--)
                if (m[i] == '.')
                    p = 1;
            if (p == 1)
                for (i = l - 1; i >= u; i--)
                    if (m[i] == '0')
                        l--;
                    else
                        break;
            for (i = l - 1; i >= u; i--)
                if (m[i] != '.')
                {
                    a[la++] = m[i] - '0';
                    b[lb++] = m[i] - '0';
                }
                else
                    k = la - 1;
            la--;
            lb--;
            if (f == 0)
            {
                la--;
                lb--;
            }
            k *= n;
            j = k;
            for (i = 0; i < n - 1; i++)
                gaocheng(a, b, lb);
            if (f == 1)
                for (i = la; i > k; i--)
                    cout << a[i];
            for (i = 1; i <= k; i++)
                if (a[i] == 0)
                    j--;
                else
                    break;
            if (j != 0)
                cout << '.';
            if (f == 0)
            {
                for (i = 1; i <= j - la; i++)
                    cout << '0';
                for (i = la; i > 0; i--)
                    cout << a[i];
            }
            if (f == 1)
                for (i = j; i > 0; i--)
                    cout << a[i];
        }
        cout << endl;
    }

    return 0;
}
