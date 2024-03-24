#include <iostream>

using namespace std;

int main()
{
    int A;
    int B;
    int C;
    
    cin >> A >> B >> C;
    
    int minute = (B + C) % 60;
    int hour = A + ((B + C) / 60);
    hour %= 24;
    
    cout << hour << ' ' << minute;

    return 0;
}
