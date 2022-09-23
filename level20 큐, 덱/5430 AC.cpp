#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        deque<int> d;

        // input
        cin.ignore(2);
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            d.push_back(input);
            cin.ignore(1);
        }
        cin.ignore(1);

        // bool을 토글해가면서 뺄 위치를 앞 뒤로 바꿔감
        bool bIsFrontMode = true;
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == 'R')
            {
                bIsFrontMode = !bIsFrontMode;
            }
            else
            {
                if (d.empty() == true)
                {
                    cout << "error\n";
                    goto NEXT_TEST_CASE;
                }

                if (bIsFrontMode == true)
                {
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }

        // result print
        cout << '[';
        if (bIsFrontMode == true)
        {  
            while (d.empty() == false)
            {
                cout << d.front();
                d.pop_front();

                if (d.empty() == false)
                {
                    cout << ',';
                }
            }
        }
        else
        {
            while (d.empty() == false)
            {
                cout << d.back();
                d.pop_back();

                if (d.empty() == false)
                {
                    cout << ',';
                }
            }
        }
        cout << "]\n";

    NEXT_TEST_CASE:;
    }
}
