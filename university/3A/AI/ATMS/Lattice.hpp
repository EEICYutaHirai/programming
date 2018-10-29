#ifndef _LATTICE_HPP_
#define _LATTICE_HPP_

#include "Node.hpp"
#include <thread>

class Lattice
{
  private:
  protected:
    int n_element;
    vector<Node *> v_node;
    long long max_id;
    long long n_good;
    long long n_no_good;
    long long pow(long long x, long long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 0)
            return pow(x * x, n / 2);
        else
            return x * pow(x, n - 1);
    }

    /*
    void set_vec(long long start, long long end)
    {
        for (long long i = start; i < end; i++)
        {
            mtx.lock();
            v_node.push_back(new Node(i, n_element));
            mtx.unlock();
        }
    }
    */
    //条件を書く
    virtual void condition() = 0;

  public:
    Lattice(int n_element) : n_no_good(0), n_element(n_element)
    {
        max_id = pow(11, n_element) - 1;

        for (long long i = 0; i <= max_id; i++)
        {
            v_node.push_back(new Node(i, n_element));
        }

        n_good = v_node.size();
    }
    virtual long long get_max_id()
    {
        return max_id;
    }
    void solve()
    {
        condition();
    }
};

#endif //_LATTICE_HPP_