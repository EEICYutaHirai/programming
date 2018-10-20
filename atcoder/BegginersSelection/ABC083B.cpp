#include <iostream>

using namespace std;

int main(){
    int N, A, B;
    int ans = 0;
    cin >> N >> A >> B;

    for(int i = 1; i <= N; i++){
        int count = 0;
        int temp;
        count += i / 10000;
        temp = i % 10000;
        count += temp / 1000;
        temp = i % 1000;
        count += temp / 100;
        temp = temp % 100;
        count += temp / 10;
        temp = temp % 10;
        count += temp;
        if(A <= count && count <= B){
            ans += i;
        }
    }
    cout << ans << endl;
}