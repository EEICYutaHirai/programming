/*
title:Exponentitation

url:http://poj.org/problem?id=1001

author:Yuta Hirai

date:2018/8/6

Exponentiation
Time Limit: 500MS		Memory Limit: 10000K
Total Submissions: 180784		Accepted: 43581
Description

Problems involving the computation of exact values of very large magnitude and precision are common. 
For example, the computation of the national debt is a taxing experience for many computer systems. 

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) 
and n is an integer such that 0 < n <= 25.

Input
The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.

Output
The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

#define MAX 255

using namespace std;

//順番を入れ替える
void swap_order(int *a)
{
    int count = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (a[i] == -1)
        {
            break;
        }
        count++;
    }
    int b[MAX]; //退避用
    for (int i = 0; i < count; i++)
    {
        b[i] = a[count - i - 1];
    }
    for (int i = 0; i < count; i++)
    {
        a[i] = b[i];
    }
}

//n桁x(1桁)を計算する関数
void cal_simple_mul(int *a, int b, int *ans)
{
    //cin はけた上がりの数
    //ans[i] = -1 を終端文字とする。
    int cin = 0;
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (a[i] == -1)
        {
            if (cin != 0)
            {
                ans[i] = cin;
                ans[i + 1] = -1;
            }
            else
            {
                ans[i] = -1;
            }
            break;
        }
        int temp = a[i] * b + cin;
        ans[i] = temp % 10;
        cin = temp / 10;
    }
    swap_order(ans);
}

//n桁xn桁の掛け算をcharで行うプログラム
//aは配列、n_aは桁数
//a[0]に1の位のかずがはいる。
void cal_mul(int *a, int *b, int *ans)
{
    int count_b;
    for (int i = 0; i < MAX; i++)
    {
        if (b[i] == -1)
        {
            break;
        }
        count_b++;
        cout << b[i] << endl;
    }
    int **temp_ans = malloc(sizeof(int *) * count_b);
    for (int i = 0; i < count_b; i++)
    {
        temp_ans[i] = malloc(sizeof(int) * MAX);
    }

    for (int i = 0; i < count_b; i++)
    {
        cal_simple_mul(a, b[i], temp_ans[i]);
    }
    //temp[last][last] = -1 で終了
    int j = 0;
    int cin = 0;
    while (1)
    {
        int temp = cin;
        int count_minus = 0;
        //各段の足し算
        for (int i = 0; i <= j; j++)
        {
            if (j < count_b)
            {
                if (temp_ans[j][j - i] == -1)
                {
                    temp_ans[j][j - i + 1] = -1;
                    count_minus++;
                }
                else
                {
                    temp += temp_ans[j][j - i];
                }
            }
        }
        if (count_minus == count_b)
        {
            ans[j] = cin;
            break;
        }
        ans[j] = temp % 10;
        cin = temp / 10;
        j++;
    }
    swap_order(ans);
    for (int i = 0; i < count_b; i++)
    {
        free(temp_ans[i]);
    }
    free(temp_ans);
}

int main()
{
    char input_char[MAX]; //input number; 0<=input[i]<=9
    int input[MAX];
    for (int i = 0; i < MAX; i++)
    {
        input[i] = -1;
    }
    int R;
    int exponent = 0;
    //input 95.123 => input[0]=3, input[1] = 2 ... exponent = 3
    //input[end] = -1
    int i_ = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> input_char[i];
        if (input_char[i] == '.')
        {
            R = 5 - i;
        }
        else
        {
            input[4 - i_] = input_char[i] - '0';
            i_++;
        }
    }
    input[i_] = -1;

    /*
    for (int i = 0; i < MAX; i++)
    {
        if (input[i] == -1)
        {
            break;
        }
        cout << input[i] << endl;
    }
    */

    //get R
    cin >> R;

    int ans[MAX];

    cal_mul(input, input, ans);
    for (int i = 0; i < MAX; i++)
    {
        if (ans[i] == -1)
        {
            break;
        }
        else
        {
            cout << ans[i];
        }
    }
}