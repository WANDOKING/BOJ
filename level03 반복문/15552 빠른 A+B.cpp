#include <iostream>

using namespace std;

int main()
{
    // C++ 입출력을 더 빠르게 하기 위함
    // cin과 cout의 묶음을 풀고, C와 C++의 버퍼를 분리
    // endl은 사용하지 않는다 (대신 '\n'을 사용하여 버퍼를 마지막에만 비운다)
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A;
        int B;
        
        cin >> A >> B;
        
        cout << A + B << '\n';
    }

    return 0;
}
