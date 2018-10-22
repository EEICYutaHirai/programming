#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    int min = 0;
    int min_pow = 1;
    int x;
    cin >> x;
    while(x%2 == 0){
        x /= 2;
        min++;
        min_pow *= 2;
    }
    for(int i = 0; i < N-1; i++){
        cin >> x;
        while(x%(min_pow) != 0){
            min_pow /= 2;
            min--;
        }
    }
    cout << min << endl;
}