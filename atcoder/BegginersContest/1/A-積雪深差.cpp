/*
title:A - 積雪深差

url:https://abc001.contest.atcoder.jp/tasks/abc001_1

author:Yuta Hirai

date:2018-8-10

problem:
ある時刻の積雪深 H1 と その 1 時間前の積雪深 H2 が与えられます。
この時、この 1 時間の積雪深差 H1 − H2 の値を計算して出力してください。

input:
入力は以下の形式で標準入力から与えられる。
H1
H2
1 行目には、整数で、ある時刻の積雪深 H1 (0≦H1≦2,000) が与えられる。
2 行目には、整数で、1 時間前の積雪深 H2 (0≦H2≦2,000) が与えられる。

output:
出力
積雪深差 H1 − H2 の値を 1 行で出力せよ。
また、出力の末尾には改行を入れること。

*/

#include <iostream>

using namespace std;

int main()
{
    int H1, H2;
    cin >> H1 >> H2;
    cout << H1 - H2 << endl;
    return 0;
}