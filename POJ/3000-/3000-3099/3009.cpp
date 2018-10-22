/*
title: Curling 2.0

url:http://poj.org/problem?id=3009

うまい書き方がどうしてもわからず、https://inazz.jp/pku/3009/を参考にした。
綺麗だった綺麗だった...
ただし、再帰のところはもっと上手く描けたと思った。(引数が二つで済んでいる。)
ちなみにメモ化は使えない
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

int w, h;
bool stones[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy;
int gx, gy;

//戻り値は答え(何回でゴールにたどり着いたか,あるいはたどり着けなかった時には-1)を返す
//cx, cyは現在の場所
int solve(int cx, int cy)
{
    int ans = 11;
    int x;
    int y;
    int mv_count;
    bool mv_success;
    REP(i, 4)
    {
        //マイルーぷ初期化し直す必要あり。
        x = cx;
        y = cy;
        mv_success = true;
        //1マスも進めない場合を除かないといけないので、countしておく
        mv_count = -1;
        //stoneにぶつかるまで進む
        while (!(stones[x][y]))
        {
            x += dx[i];
            y += dy[i];
            //もし途中でゴールしたら、それ以上「深く」考える必要なし
            if (x == gx && y == gy)
            {
                return 1;
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
            //進みすぎたので石の手前に戻す
            ans = min(ans, solve(x - dx[i], y - dy[i]) + 1);
            //ここで戻すのがとても大事
            //戻さなければ、他の方向に移動させるときに、ここで石をなくした影響が出てしまう。
            stones[x][y] = true;
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

        REP(i, w)
        {
            REP(j, h)
            {
                scanf("%d", &tmp);
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
        int ans = solve(sx, sy);
        printf("%d\n", ans > 10 ? -1 : ans);
    }
    return 0;
}