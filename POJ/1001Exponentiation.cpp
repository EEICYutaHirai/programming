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

JavaのDecimal が楽らしい
*/
#include <iostream>
#include <math.h>

using namespace std;

//ex 95.123 n_digit=5, dot_position = 3(from right)
typedef struct
{
    int n_digit;  //桁数
    int num[256]; //charのほうがいいかもしれないけどなんかおかしくなる 128だとたりない。
    int dot_pos;  //右から数えての点の位置
} exnum;          //exact number;

//与えられたdoubleが整数かどうかチェック
int is_int(double n)
{
    if (ceil(n) == floor(n))
    {
        return 1;
    }
    return 0;
}

int get_n_digit(int n)
{
    int n_digit = 0;
    int n_digit_dec = 1;
    while ((int)(n / n_digit_dec) != 0)
    {
        n_digit++;
        n_digit_dec *= 10;
    }
    return n_digit;
}

//input double and return appropriate exnum
exnum init_exnum(double n)
{
    int dot_pos = 0;
    int dot_pos_dec = 1; //10^exp
    //指数をけってい ex 95.123 => exp = 2
    while (!is_int(n * dot_pos_dec))
    {
        dot_pos++;
        dot_pos_dec *= 10;
    }

    //numと桁数を決定
    int n_int = n * dot_pos_dec; //必ず整数になるはず
    int n_digit = get_n_digit(n_int);
    int n_digit_dec = 1;
    for (int i = 0; i < n_digit - 1; i++)
    {
        n_digit_dec *= 10;
    }

    exnum ex;
    for (int i = 0; i < n_digit; i++)
    {
        ex.num[n_digit - i - 1] = (int)(n_int / n_digit_dec);
        n_int = n_int - ex.num[n_digit - i - 1] * n_digit_dec;
        n_digit_dec /= 10;
    }
    ex.dot_pos = dot_pos;
    ex.n_digit = n_digit;

    if (ex.dot_pos == 0 && ex.n_digit == 0)
    {
        ex.n_digit = 1;
        ex.num[0] = 0;
    }

    return ex;
}

void print_exnum(exnum ex)
{
    for (int j = 0; j < ex.dot_pos - ex.n_digit; j++)
    {
        if (j == 0)
        {
            cout << '.';
        }
        cout << 0;
    }
    for (int i = 0; i < ex.n_digit; i++)
    {

        if (i == ex.n_digit - ex.dot_pos)
        {
            cout << '.';
        }
        cout << ex.num[ex.n_digit - i - 1];
    }
    cout << endl;
}

exnum cal_simple_mul(exnum ex, int n)
{
    int cin = 0;
    exnum ans_ex;
    for (int i = 0; i < ex.n_digit; i++)
    {
        int temp = cin + n * ex.num[i];
        ans_ex.num[i] = temp % 10;
        cin = (int)(temp / 10);
    }
    if (cin == 0)
    {
        ans_ex.n_digit = ex.n_digit;
    }
    else
    {
        ans_ex.n_digit = ex.n_digit + 1;
        ans_ex.num[ex.n_digit] = cin;
    }
    ans_ex.dot_pos = ex.dot_pos;
    return ans_ex;
}

exnum cal_mul(exnum ex1, exnum ex2)
{
    exnum ex_temp[ex2.n_digit];
    exnum ex_ans;
    for (int i = 0; i < ex2.n_digit; i++)
    {
        ex_temp[i] = cal_simple_mul(ex1, ex2.num[i]);
    }
    ex_ans.n_digit = ex2.n_digit - 1 + ex_temp[ex2.n_digit - 1].n_digit;
    ex_ans.dot_pos = ex1.dot_pos + ex2.dot_pos;
    int cin = 0;
    for (int i = 0; i < ex_ans.n_digit; i++)
    {
        int temp = cin;
        for (int j = 0; j < ex2.n_digit; j++)
        {
            if (i >= j && i <= j + ex_temp[j].n_digit - 1)
            {
                temp += ex_temp[j].num[i - j];
            }
        }
        ex_ans.num[i] = temp % 10;
        cin = (int)(temp / 10);
    }
    if (cin != 0)
    {
        ex_ans.num[ex_ans.n_digit] = cin;
        ex_ans.n_digit++;
    }
    return ex_ans;
}

exnum cal_ans(exnum ex, int R)
{
    exnum ans = ex;
    for (int i = 0; i < R - 1; i++)
    {
        ans = cal_mul(ex, ans);
    }
    return ans;
}

int main()
{
    //declare input
    double N;
    int R;

    while (cin >> N >> R)
    {
        if (R == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            exnum ex = init_exnum(N);
            exnum ex1 = cal_ans(ex, R);
            print_exnum(ex1);
        }
    }
    return 0;
}