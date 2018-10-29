#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <vector>

using namespace std;

class Node
{
    long long id;
    int is_true;
    //最大の要素数
    int n_element;
    //実質幾つの要素もつか
    int level;
    //集合,10ならそれはemptyを意味するとする。
    vector<int> set;

  protected:
  public:
    Node(long long id, int n_element) : id(id), is_true(true), n_element(n_element)
    {
        long long tmp = id;
        for (int i = 0; i < n_element; i++)
        {
            int x = tmp % n_element;
            x--;
            if (x > 0)
            {
                level++;
            }
            set.push_back(x);
            tmp = (tmp - (x + 1)) / 11;
        }
    }
    virtual vector<int> get_set()
    {
        return set;
    }
    virtual int get_level()
    {
        return level;
    }
};

#endif