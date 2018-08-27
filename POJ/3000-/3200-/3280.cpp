#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define swap(a, b) ((a) += (b), (b) = (a) - (b), (a) -= (b))

/*
得られた知見
union find の美しいコード
cin, cout はクソ遅いのでcstdioを使おう
(cin, cout でTLEだったのが, scanfでACになった)
*/

struct UnionFind
{
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool union_set(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find_set(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x)
    {
        return -data[root(x)];
    }
};

int main()
{
    int n_anim, n_info;
    cin >> n_anim >> n_info;

    int ans = 0;
    UnionFind union_find(3 * n_anim);

    int type[n_info], x[n_info], y[n_info];
    for (int i = 0; i < n_info; i++)
    {
        scanf("%d %d %d", &type[i], &x[i], &y[i]);
    }

    for (int i = 0; i < n_info; i++)
    {
        if (x[i] < 0 || x[i] > n_anim || y[i] < 0 || y[i] > n_anim)
        {
            ans++;
        }
        else
        {
            if (type[i] == 1)
            {
                if (union_find.find_set(3 * (x[i] - 1), 3 * (y[i] - 1) + 1) || union_find.find_set(3 * (x[i] - 1), 3 * (y[i] - 1) + 2))
                {
                    ans++;
                }
                else
                {
                    union_find.union_set(3 * (x[i] - 1), 3 * (y[i] - 1));
                    union_find.union_set(3 * (x[i] - 1) + 1, 3 * (y[i] - 1) + 1);
                    union_find.union_set(3 * (x[i] - 1) + 2, 3 * (y[i] - 1) + 2);
                }
            }
            else
            {
                if (union_find.find_set(3 * (x[i] - 1), 3 * (y[i] - 1)) || union_find.find_set(3 * (x[i] - 1), 3 * (y[i] - 1) + 2))
                {
                    ans++;
                }
                else
                {
                    union_find.union_set(3 * (x[i] - 1), 3 * (y[i] - 1) + 1);
                    union_find.union_set(3 * (x[i] - 1) + 1, 3 * (y[i] - 1) + 2);
                    union_find.union_set(3 * (x[i] - 1) + 2, 3 * (y[i] - 1));
                }
            }
        }
    }
    cout << ans << endl;
}