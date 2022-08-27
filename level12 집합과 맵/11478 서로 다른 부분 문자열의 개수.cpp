#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main()
{
    const int MAX_LENGTH = 1000;
    char S[MAX_LENGTH + 1];
    set<string> subStrs;
    scanf("%s", S);
    
    int length = strlen(S);
    int count = 0;
    for (int i = 1; i <= length; i++) {
        for (int j = 0; j <= length - i; j++) {
            string subStr(S + j, i);
            
            bool bSuccess = subStrs.insert(subStr).second;
            
            if (bSuccess) {
                count++;
            }
        }
    }
    
    printf("%d", count);
    
    return 0;
}
