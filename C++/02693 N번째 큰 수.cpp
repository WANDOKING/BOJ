#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    int arr[10];
    
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[j];
        }
        
        sort(arr, arr + 10);
        
        cout << arr[7] << '\n';
    }
    

    return 0;
}
