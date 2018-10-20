#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[0] != 'A'){
        cout << "WA" <<endl;
        return 0;
    }

    int count = 0;
    for(int i = 2; i < S.size() - 1; i++){
        if(S[i] == 'C'){
            count ++;
        }
    }
    if(count != 1){
        cout << "WA" << endl;
        return 0;
    }

    count = 0;
    for(int i = 0; i < S.size(); i++){
        if(isupper(S[i])){
            count ++;
        }
    }

    if(count != 2){
        cout << "WA" << endl;
        return 0;
    }

    cout << "AC" << endl;
    return 0;
}