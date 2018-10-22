#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef pair<int, int> pair2;

int main()
{
    int N;
    cin >> N;
    pair<int, int> data[N];
    for (int i = 0; i < N; i++)
    {
        cin >> data[i].first >> data[i].second;
    }
    sort(data, data + N, greater<pair2>());
    int L, P;
    cin >> L >> P;
    priority_queue<int> que;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        P -= L - data[i].first;

        while (P < 0)
        {
            if (que.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            P += que.top();
            que.pop();
            ans++;
        }

        que.push(data[i].second);
        L = data[i].first;
    }

    P -= L;
    while (P < 0)
    {
        if (que.empty())
        {
            cout << -1 << endl;
            return 0;
        }
        P += que.top();
        que.pop();
        ans++;
    }

    cout << ans << endl;
}