#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int num1;
        int num2;

        cin >> num1 >> num2;

        if (num1 == 0 && num2 == 0)
        {
            break;
        }
        else if (num1 > num2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
