#include <iostream>

using namespace std;

#define MAX_N 2500

int main()
{
    int N;
    cin >> N;
    char cow[MAX_N];
    for (int i = 0; i < N; i++)
    {
        cin >> cow[i];
    }
    char ans[N];
    int first_index = 0;
    int last_index = N - 1;
    int ans_index = 0;
    while (ans_index < N)
    {
        for (int i = 0; i <= last_index - first_index; i++)
        {
            if (cow[first_index + i] < cow[last_index - i])
            {
                ans[ans_index] = cow[first_index];
                ans_index++;
                first_index++;
                break;
            }
            else if (cow[first_index + i] > cow[last_index - i])
            {
                ans[ans_index] = cow[last_index];
                ans_index++;
                last_index--;
                break;
            }
            else if (i == last_index - first_index)
            {
                ans[ans_index] = cow[last_index];
                ans_index++;
                last_index--;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i];
        if ((i + 1) % 80 == 0)
            cout << endl;
    }
    cout << endl;
}