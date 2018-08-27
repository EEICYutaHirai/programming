/*
https://beta.atcoder.jp/contests/abc104/tasks/abc104_c
*/

/*
方針
まず初めにてんすうの取りうる最大値をかんがえる。そのご、その状態で解くのをやめたときに、
減る点数が最小になる問題を考え、減らしていく。
*/

#include <iostream>

using namespace std;

int get_score(int *p, int *c, int *ans, int D){
    int sum = 0;
    for(int i = 0;i < D; i++){
        sum += 100 * (i + 1) * ans[i];
        if(ans[i] == p[i]){
            sum += c[i];
        }
    }
    return sum;
}

//解くのをやめたときに点数の減りがもっとも小さいな問題の時の減少する点数を返す
int get_least_score(int *p, int *c, int *ans, int D){
    int G_max = get_score(p, c, ans, D);

    //しょきじょうたいせってい　
    int min_index = -1;
    int min = -1;

    for(int i = 0; i < D; i++){
        int decrease_score = 100 * (i + 1);
        if(p[i] > 0){
            if(ans[i] == p[i]){
                decrease_score += c[i];
            }
            if(min == -1){
                min = decrease_score;
                min_index = i;
            }
            if(min >= decrease_score){
                min = decrease_score;
                min_index = i;
            }
        }
    }
    cout << min_index <<endl;
    cout << min << endl;
    ans[min_index]--;
    return min;
}

int main(){
    int D, G;
    cin >> D >> G;

    int p[D];
    int c[D];
    for(int i = 0;i < D; i++){
        cin >> p[i] >> c[i];
    }

    int ans[D];
    for(int i = 0; i < D; i++){
        ans[i] = p[i];
    }

    int G_max  = get_score(p, c, p, D);
    int count = 0;
    while(1){
        if((G_max -= get_least_score(p, c, ans, D)) >= G){
            count++;
        }else{
            break;
        }
    }
    cout << count << endl;
}