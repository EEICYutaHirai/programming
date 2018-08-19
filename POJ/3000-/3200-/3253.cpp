/*TLE*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> data(N);
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    sort(data.begin(), data.end(), greater<int>());
    ll ans = 0;
    while (data.size() > 1)
    {
        ans += data[data.size() - 1] + data[data.size() - 2];
        data[data.size() - 2] += data[data.size() - 1];
        data.pop_back();
        sort(data.begin(), data.end(), greater<int>());
    }
    cout << ans << endl;
    return 0;
}