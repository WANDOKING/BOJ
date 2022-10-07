#include <iostream>
#include <map>
#include <cassert>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int testOpNum;
        cin >> testOpNum;

        map<int, int> q;
        for (int i = 0; i < testOpNum; i++)
        {
            char op;
            int num;

            cin >> op >> num;

            if (op == 'I')
            {
                if (q.find(num) == q.end())
                {
                    q.insert(make_pair(num, 1));
                }
                else
                {
                    q[num]++;
                }
            }
            else if (op == 'D')
            {
                if (q.empty() == false)
                {
                    if (num == 1)
                    {
                        map<int, int>::reverse_iterator it = q.rbegin();

                        if (it->second > 1)
                        {
                            it->second--;
                        }
                        else
                        {
                            q.erase(it->first);
                        }
                    }
                    else if (num == -1)
                    {
                        map<int, int>::iterator it = q.begin();

                        if (it->second > 1)
                        {
                            it->second--;
                        }
                        else
                        {
                            q.erase(it->first);
                        }
                    }
                    else
                    {
                        assert(false);
                    }
                }
            }
            else
            {
                assert(false);
            }
        }

        if (q.empty() == true)
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << q.rbegin()->first << ' ' << q.begin()->first << '\n';
        }
    }
}
