#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int N;
    cin >> N;
    int t[N+1];
    int x[N+1];
    int y[N+1];
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for(int i = 1; i < N+1; i++){
        cin >> t[i];
        cin >> x[i];
        cin >> y[i];
    }
    for(int i = 0; i < N; i++){
        int sum = (t[i+1] - t[i]) - abs(x[i+1] - x[i]) - abs(y[i+1] - y[i]);
        if(sum >= 0 && sum%2 == 0){
            continue;
        }else{
            cout << "No" <<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}