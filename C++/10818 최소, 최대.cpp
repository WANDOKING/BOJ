#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int N;
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        
        if (input < minNum) {
            minNum = input;
        }
        
        if (input > maxNum) {
            maxNum = input;
        }
    }
    
    cout << minNum << ' ' << maxNum;
    return 0;
}
