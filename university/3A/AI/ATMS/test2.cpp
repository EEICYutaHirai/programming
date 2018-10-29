#include <unordered_set>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 8;
    int n_per = 11;
    long long n_need = 1;
    string ss[8] = {"S", "E", "N", "D", "M", "O", "R", "Y"};
    for (int i = 0; i < n; i++)
    {
        n_need *= n_per;
    }
    unordered_set<string> test;
    for (long long i = 0; i < n_need; i++)
    {
        long long tmp = i;
        string s = "";
        for (long long j = 0; j < 8; j++)
        {
            int tmp_amari = tmp % 11;
            tmp_amari--;
            if (tmp_amari != -1)
            {
                s = s + ss[j] + to_string(tmp_amari) + " ";
            }
        }
    }
    return 0;
}