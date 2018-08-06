/*
title:三角形(p.21)

url:蟻本p.21

author:Yuta Hirai

date:2018/8/6

problem:
n本の棒があります。棒iのながさはa_iです。それらの棒から３本を選んで
できるだけ周長のながい三角形を作ろうと考えています。最大の周長を求めなさい。
ただし三角形が作れない場合は答えを０としなさい。

input:

output:

*/

#include <iostream>

using namespace std;

//選んだ辺の長さで三角形を作ることができるかどうか。
//作れるなら周長を返し、作れないなら0を返す
int get_round_length(int x, int y, int z)
{
    int side[3] = {x, y, z};
    for (int i = 0; i < 3; i++)
    {
        if (side[i] >= (side[(i + 1) % 3] + side[(i + 1) % 2]))
        {
            return 0;
        }
    }
    return x + y + z;
}

int main()
{
    //receive input
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int temp;
                if ((temp = get_round_length(a[i], a[j], a[k])) > max_size)
                {
                    max_size = temp;
                }
            }
        }
    }
    cout << max_size << endl;
}