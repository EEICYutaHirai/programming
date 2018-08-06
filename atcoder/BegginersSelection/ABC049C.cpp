#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
難しかったのでぐぐって参考にした
*/

//共通で使うものはmainの外に書いたほうがいい？
string divide[4] = {"maerd", "remaerd", "resare", "esare"};

int main(){
    string S;
    cin >> S;
    //順序を逆にすることで解きやすくなるという天才的解法
    reverse(S.begin(), S.end());

    bool ans_bool = true;

    //下のような美しい書き方ができる！
    for(int i = 0; i < S.size(); ){
        bool temp = false;
        for(int j = 0; j < 4; j++){
            if(S.substr(i, divide[j].size()) == divide[j]){
                i += divide[j].size();
                temp = true;
            }
        }
        if(!temp){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}