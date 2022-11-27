#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int maxNum = INT_MIN;
    int maxNumIndex = 0; 
    
    for (int i = 1; i <= 9; i++) {
        int input;
        cin >> input;
        
        if (input > maxNum) {
            maxNum = input;
            maxNumIndex = i;
        }
    }
    
    cout << maxNum << '\n' << maxNumIndex;
    return 0;
}
