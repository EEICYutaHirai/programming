
#include <iostream>

using namespace std;
bool field[30][30];
int w, h;
int sx, sy, gx, gy;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dfs(int x, int y, int level)
{
    if (level == 10)
        return 11;
    int ans = 11;
    for (int d = 0; d < 4; d++)
    {
        int cx = x, cy = y;
        int nx = cx + dx[d], ny = cy + dy[d];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h)
            continue;
        if (field[ny][nx])
            continue;
        bool failed = false;
        while (true)
        {
            cx = nx;
            cy = ny;
            if (cx == gx && cy == gy)
                return level + 1;
            nx = cx + dx[d];
            ny = cy + dy[d];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h)
            {
                failed = true;
                break;
            }
            if (field[ny][nx])
                break;
        }
        if (!failed)
        {
            field[ny][nx] = false;
            ans = min(ans, dfs(cx, cy, level + 1));
            field[ny][nx] = true;
        }
    }
    return ans;
}
int main(void)
{
    while (true)
    {
        cin >> w >> h;
        if (!(w | h))
            break;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
            {
                int t;
                cin >> t;
                field[y][x] = (t == 1);
                if (t == 2)
                {
                    sx = x;
                    sy = y;
                }
                else if (t == 3)
                {
                    gx = x;
                    gy = y;
                }
            }
        int ans = dfs(sx, sy, 0);
        cout << (ans == 11 ? -1 : ans) << endl;
    }
    return 0;
}
