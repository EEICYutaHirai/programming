#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int d[N];
    for(int i = 0; i < N; i++){
        cin >> d[i];
    }

    int count = 0;
    for(int i = 0; i < N; i++){ 
        if(d[i] != 0){
            int temp = d[i];
            for(int j = i; j < N; j++){
                if(d[j] == temp){
                    d[j] = 0;
                }
            }   
            count++;
        }
    }

    cout << count << endl;
}