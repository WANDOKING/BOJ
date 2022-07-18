#include <iostream>

using namespace std;

int main()
{
    int T;
    int A;
    int B;
    
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        cin >> A >> B;
        printf("Case #%d: %d\n", i, A + B);
    }

    return 0;
}
