#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_prime(ll N)
{
    ll sq = sqrt(N);
    for (int i = 2; i <= sq; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

int original_pow(ll i, int N)
{
    int mod = N;
    ll ans = 1;
    while (N > 0)
    {
        if (N & 1)
            ans = ans * i % mod;
        i = i * i % mod;
        N >>= 1;
    }
    return ans;
}

bool is_carmichael(int N)
{
    if (is_prime(N))
    {
        return false;
    }
    for (int i = 2; i <= N - 1; i++)
    {
        if (original_pow(i, N) % N != i)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
        {
            return 0;
        }
        if (is_carmichael(N))
        {
            cout << "The number " << N << " is a Carmichael number." << endl;
        }
        else
        {
            cout << N << " is normal." << endl;
        }
    }
}