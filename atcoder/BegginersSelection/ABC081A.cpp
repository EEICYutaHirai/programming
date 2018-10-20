#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int count = 0;
    for (int i = 0; i < 3; i++){
        char x;
        cin >> x;
        if(x - '0'){
            count++;
        }
    }
    cout << count;
}