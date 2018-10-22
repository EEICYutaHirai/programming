#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int alice = 0, bob = 0;
    for(int i = 0; i < N; i++){
        int max = 0;
        int max_index = 0;
        for(int j = 0; j < N; j++){
            if(a[j] > max){
                max = a[j];
                max_index = j;
            }
        }
        if(i%2 == 0){
            alice += max;
        }else {
            bob += max;
        }
        a[max_index] = 0;
    }
    cout << alice - bob <<endl;
}