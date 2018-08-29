/*
title:

url:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <limits>
#include <utility>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

/*配列と違い、vectorは破壊されない。*/

/*
void test(vector<int> v)
{
    v.push_back(3);
}

int main()
{
    vector<int> v;
    v.push_back(3);
    cout << v.size() << endl;
    test(v);
    cout << v.size() << endl;
}
*/

//オブジェクトも破壊されない
//多分参照を渡している訳ではないから

struct Test
{
    int a;
    int data[2][2];
    Test(int _a) : a(_a) { data[0][0] = _a; };
};

void test(Test t)
{
    t.a += 4;
    t.data[0][0] += 4;
}

int main()
{
    Test test_test(2);
    cout << test_test.data[0][0] << endl;
    test(test_test);
    cout << test_test.data[0][0] << endl;
}