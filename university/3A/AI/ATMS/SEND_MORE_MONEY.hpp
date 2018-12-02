#ifndef _SEND_MORE_MONEY_HPP_
#define _SEND_MORE_MONEY_HPP_

#include "Lattice.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>

using namespace std;

class SEND_MORE_MONEY : public Lattice
{
    int n_element = 8;

  protected:
    virtual void condition()
    {
        string s_problem[8] = {"S", "E", "N", "D", "M", "O", "R", "Y"};
        cout << "Start solving SEND+MORE=MONEY." << endl;

        cout << "1. M!=1." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[4] != 1)
            {
                //delete v_node[i];
                cout << v_node.size() << endl;
                cout << i << endl;
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "2. S=0." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[0] == 0)
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "3. D+E!=Y(mod10)." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[1] != -1 &&
                v_node[i]->get_set()[3] != -1 &&
                v_node[i]->get_set()[7] != -1 &&
                (v_node[i]->get_set()[1] + v_node[i]->get_set()[3]) % 10 != v_node[i]->get_set()[7])
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "5. N+R!=E(mod10) or N+R!=E-1(mod10)." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[2] != -1 &&
                v_node[i]->get_set()[6] != -1 &&
                v_node[i]->get_set()[1] != -1 &&
                (((v_node[i]->get_set()[2] + v_node[i]->get_set()[6]) % 10 != v_node[i]->get_set()[1]) ||
                 ((v_node[i]->get_set()[2] + v_node[i]->get_set()[6]) % 10 != v_node[i]->get_set()[1] - 1)))
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "6. E+O!=N(mod10) or E+O!=N-1(mod10)." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[1] != -1 &&
                v_node[i]->get_set()[5] != -1 &&
                v_node[i]->get_set()[2] != -1 &&
                (((v_node[i]->get_set()[1] + v_node[i]->get_set()[5]) % 10 != v_node[i]->get_set()[2]) ||
                 ((v_node[i]->get_set()[1] + v_node[i]->get_set()[5]) % 10 != v_node[i]->get_set()[2] - 1)))
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "7. S+M!=O(mod10) or S+M!=O-1(mod10)." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            if (v_node[i]->get_set()[0] != -1 &&
                v_node[i]->get_set()[4] != -1 &&
                v_node[i]->get_set()[5] != -1 &&
                (((v_node[i]->get_set()[0] + v_node[i]->get_set()[4]) % 10 != v_node[i]->get_set()[5]) ||
                 ((v_node[i]->get_set()[0] + v_node[i]->get_set()[4]) % 10 != v_node[i]->get_set()[5] - 1)))
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "8. Another character has another value." << endl;
        for (int i = 0; i < n_element; i++)
        {
            for (int j = i + 1; j < n_element; j++)
            {
                for (long long k = 0; i < v_node.size(); i++)
                {
                    if (v_node[k]->get_set()[i] == v_node[k]->get_set()[j])
                    {
                        //delete v_node[k];
                        v_node.erase(v_node.begin() + k);
                        k--;
                        n_no_good++;
                        n_good--;
                    }
                }
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;

        cout << "9. SEND+MORE!=MONEY." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            vector<int> tmp = v_node[i]->get_set();
            int send = tmp[0] * 1000 + tmp[1] * 100 + tmp[2] * 10 + tmp[3];
            int more = tmp[4] * 1000 + tmp[5] * 100 + tmp[6] * 10 + tmp[1];
            int money = tmp[4] * 10000 + tmp[5] * 1000 + tmp[2] * 100 + tmp[1] * 10 + tmp[7];
            if (send + more != money)
            {
                //delete v_node[i];
                v_node.erase(v_node.begin() + i);
                i--;
                n_no_good++;
                n_good--;
            }
        }
        cout << "No GOOD: " << n_no_good << " GOOD: " << n_good << endl;
        cout << endl;
        cout << "ans is ..." << endl;
        for (long long i = 0; i < v_node.size(); i++)
        {
            vector<int> tmp = v_node[i]->get_set();
            for (int j = 0; j < 8; j++)
            {
                cout << s_problem[j] << tmp[j] << " ";
            }
            cout << endl;
        }
    }

  public:
    SEND_MORE_MONEY() : Lattice(8) {}
};

#endif