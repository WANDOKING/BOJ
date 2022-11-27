#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int hour;
    int minute;
    int second;
    int D;

    cin >> hour >> minute >> second >> D;

    second += D;
    
    minute += second / 60;
    second = second % 60;

    hour += minute / 60;
    minute = minute % 60;

    hour = hour % 24;

    cout << hour << ' ' << minute << ' ' << second;
}
