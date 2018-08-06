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

#define MAX 255;

using namespace std;

//n桁xn桁の掛け算をcharで行うプログラム
//aは配列、n_aは桁数
void mul_chars(char *a, int n_a, char *b, int n_b, char *ans)
{
}

int main()
{
    string s;
    int n;
    while (cin >> s >> n)
    {
        double R = stod(s);
        double ans = 1.;
        for (int i = 0; i < n; i++)
        {
            ans *= R;
        }
        cout << ans;
    }
}