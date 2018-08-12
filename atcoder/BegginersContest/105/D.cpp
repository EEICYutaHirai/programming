#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[N];
    long long amari[M];
    for (int i = 0; i < M; i++)
    {
        amari[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        amari[A[i] % M]++;
    }
    long long count = 0;
    long long sum[N];
    sum[0] = A[0];
    for (int l = 1; l < N; l++)
    {
        sum[l] = sum[l - 1] + A[l];
    }
    for (int i = 0; i < N; i++)
    {
        }
    cout << count << endl;
    return 0;
}