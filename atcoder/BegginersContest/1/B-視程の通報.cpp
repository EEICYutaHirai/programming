/*
title:B - 視程の通報

url:https://abc001.contest.atcoder.jp/tasks/abc001_2

author:Yuta Hirai

date:2018-8-10

problem:
気象情報は、世界中に様々な形で流れています。そのひとつの地上実況気象通報式 (SYNOP) では、視程 (肉眼で物体がはっきりと確認できる最大の距離) を、次の規則に従って、VVという値 (通報式) に変換して報じます。
0.1km 未満： VVの値は 00 とする。
0.1km 以上 5km 以下：距離 (km) を 10 倍した値とする。1 桁の場合は上位に 0 を付す。
例えば、2,000m =2.0km ならば、VVは 20 である。同じく、200mの場合VVは 02 である。
6km 以上 30km 以下：距離 (km) に 50 を足した値とする。
例えば、15,000m =15km ならば、VVは 65 である。
35km 以上 70km 以下：距離 (km) から 30 を引いて 5 で割った後、80 を足した値とする。
例えば、40,000m =40km ならば、VVは 82 である。
70km より大きい：VVの値は 89 とする。
いま、あなたに視程の距離をメートルで与えるので、上記のルールに従って計算されるVVを出力するプログラムを作成してください。

なお、VVは必ず（上位の 0 を含めて）2桁の整数であり、上記のルールに従って計算した時に整数にならないような入力や、上記の範囲に入らない入力 (例：5km より大きく 6km 未満) などはありません。

input:
入力は以下の形式で標準入力から与えられる。
m
1 行目には、距離を表す整数 m (0≦m≦100,000) が与えられる。単位はメートル (m) である。

output:
VVの値を 1 行で出力せよ。
また、出力の末尾には改行を入れること。

*/

#include <iostream>

using namespace std;

int main()
{
    //単位は以下全てメートル
    int input;
    cin >> input;
    if (input < 100)
    {
        cout << "00" << endl;
        return 0;
    }
    else if (input < 1000)
    {
        cout << "0" << input * 10 / 1000 << endl;
        return 0;
    }
    else if (input <= 5000)
    {
        cout << input * 10 / 1000 << endl;
    }
    else if (input <= 30000)
    {
        cout << input / 1000 + 50 << endl;
    }
    else if (input <= 70000)
    {
        cout << (input / 1000 - 30) / 5 + 80 << endl;
    }
    else
    {
        cout << 89 << endl;
    }
}