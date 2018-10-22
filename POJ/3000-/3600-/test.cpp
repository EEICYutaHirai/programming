#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int data[5][3];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            data[i][j] = i + j;
        }
    }
    //sort(&data[0], &data[4], [](int &x, int &y) { return x[0] < y[0]; });
    sort(data[0], data[0] + 3, greater<int>());
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << data[i][j];
        }
        cout << endl;
    }
}
