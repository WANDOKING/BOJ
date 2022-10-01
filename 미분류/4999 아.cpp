#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string jaehwan;
    string doctor;

    cin >> jaehwan >> doctor;

    if (jaehwan.length() >= doctor.length())
    {
        cout << "go";
    }
    else
    {
        cout << "no";
    }
}
