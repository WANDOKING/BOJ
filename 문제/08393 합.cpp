#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    // 가우스의 덧셈 O(1)
    cout << n * (n+1) / 2;

    return 0;
}
