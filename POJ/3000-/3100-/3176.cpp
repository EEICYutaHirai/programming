#include <iostream>
#include <string.h>

using namespace std;

#define MAX(a, b) ((a) > (b) ? a : b)

int N;
int score[351][351];
int memo[351][351];

int get_score(int row, int index)
{
    if (memo[row][index] >= 0)
    {
        return memo[row][index];
    }
    if (row == N - 1)
    {
        return score[row][index];
    }
    return memo[row][index] =
               score[row][index] +
               MAX(get_score(row + 1, index), get_score(row + 1, index + 1));
}

int main()
{
    memset(memo, -1, sizeof(memo));
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> score[i][j];
        }
    }
    cout << get_score(0, 0) << endl;
}