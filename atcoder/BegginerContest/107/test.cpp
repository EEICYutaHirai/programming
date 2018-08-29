#include <iostream>
#include <string>
#include <queue>

using namespace std;

//cin >> string で読み込まれるのは、空白と改行まで

int main()
{
    /*
    string tmp;
    cin >> tmp;
    cout << tmp << endl;
    */

    /*
    int j;
    for (j = 0; j < 10; j++)
    {
        if (j == 9)
            break;
    }
    cout << j << endl;
    */

    priority_queue<int> queue;
    queue.push(3);
    queue.push(1);
    cout << queue[1];
}