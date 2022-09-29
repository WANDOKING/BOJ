#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        string name;
        int age;
        int weight;

        cin >> name >> age >> weight;

        if (name == "#" && age == 0 && weight == 0)
        {
            break;
        }

        cout << name;

        if (age > 17 || weight >= 80)
        {
            cout << " Senior\n";
        }
        else
        {
            cout << " Junior\n";
        }
    }
}
