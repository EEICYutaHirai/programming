/*
https://beta.atcoder.jp/contests/abc104/tasks/abc104_a
*/

#include <iostream>

using namespace std;

int main(){
    int R;
    cin >> R;

    if(R < 1200){
        cout << "ABC" << endl;
        return 0;
    }
    if(R < 2800){
        cout << "ARC" << endl;
        return 0;
    }
    cout << "AGC" << endl;
    return 0;
}