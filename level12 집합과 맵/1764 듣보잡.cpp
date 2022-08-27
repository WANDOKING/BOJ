#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int N;
    int M;
    
    string input;
    
    scanf("%d %d", &N, &M);
    
    set<string> noHears;
    for (int i = 0; i < N; i++) {
        cin >> input;
        noHears.insert(input);
    }
    
    set<string> result;
    for (int i = 0; i < M; i++) {
        cin >> input;
        
        if (noHears.find(input) != noHears.end()) {
            result.insert(input);
        }
    }
    
    printf("%ld\n", result.size());
    
    for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
