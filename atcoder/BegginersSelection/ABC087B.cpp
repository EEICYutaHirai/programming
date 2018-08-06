#include <iostream>

using namespace std;

int main(){
    int A, B, C, X;
    int count = 0;
    cin >> A >> B >> C >> X;
    for(int i = 0; i <= A; i++){
        int sum1 = X;
        sum1 -= i * 500;
        if(sum1 < 0){
            break;
        }
        for(int j = 0; j <= B; j++){
            int sum2 = sum1 - j * 100;
            if(sum2 < 0){
                break;
            }
            for(int l = 0; l <= C; l++){
                int sum3 = sum2 - l * 50;
                if(sum3 == 0){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}