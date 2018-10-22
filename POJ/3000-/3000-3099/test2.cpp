#include <iostream>

using namespace std;

bool stones[30][30];
int w, h;
int sx, sy, gx, gy;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

/*
int solve(int cx, int cy, int depth)
{
    if (depth == 10)
    {
        return 11;
    }
    int ans = 11;
    int x;
    int y;
    int mv_count;
    bool mv_success;
    REP(i, 4)
    {
        x = cx;
        y = cy;
        mv_success = true;
        mv_count = -1;
        while (!(stones[x][y]))
        {
            x += dx[i];
            y += dy[i];
            if (x == gx && y == gy)
            {
                return 1 + depth;
            }
            if (0 > x || x >= w || 0 > y || y >= h)
            {
                mv_success = false;
                break;
            }
            mv_count++;
        }
        if (mv_success && mv_count > 0)
        {
            stones[x][y] = false;
            ans = min(ans, solve(x - dx[i], y - dy[i], depth + 1));
            stones[x][y] = true;
        }
    }
    return ans;
}
*/

int solve(int x, int y, int level)
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
        if (stones[nx][ny])
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
            if (stones[nx][ny])
                break;
        }
        if (!failed)
        {
            stones[nx][ny] = false;
            ans = min(ans, solve(cx, cy, level + 1));
            stones[nx][ny] = true;
        }
    }
    return ans;
}

int main()
{
    int tmp;
    while (true)
    {
        cin >> w >> h;
        if (!(w | h))
            break;

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                int tmp;
                cin >> tmp;
                stones[i][j] = (tmp == 1);
                if (tmp == 2)
                {
                    sx = i;
                    sy = j;
                }
                else if (tmp == 3)
                {
                    gx = i;
                    gy = j;
                }
            }
        }
        int ans = solve(sx, sy, 0);
        cout << (ans == 11 ? -1 : ans) << endl;
    }
    return 0;
}