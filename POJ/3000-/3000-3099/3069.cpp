#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    while (1)
    {
        int R, n;
        scanf("%d %d", &R, &n);
        if (R == -1 && n == -1)
        {
            break;
        }
        int position[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &position[i]);
        }
        sort(position, position + n);
        int i = 0;
        int ans = 0;
        while (i < n)
        {
            //sは今の所含まれていない最小のてん
            int s = position[i];
            while (i < n && position[i] <= s + R)
                i++;
            //pは印をつけた場所
            int p = position[i - 1];
            while (i < n && position[i] <= p + R)
                i++;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}