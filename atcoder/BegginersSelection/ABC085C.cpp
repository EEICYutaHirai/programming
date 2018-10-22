#include <iostream>

using namespace std;

int main(){
    int N, Y;
    cin >> N >> Y;
    Y /= 1000;
    int sum;
    for(int i = 0; i <= N; i++){
        for(int j = i+1; j <= N+1 ; j++){
            sum = 10 * i + 5 * (j - i- 1) + (N + 1- j);
            if(sum == Y){
                cout << i << " " << j-i-1 << " " << N+1-j << endl;
                return 0;
            } 
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}