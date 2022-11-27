#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int TESTCASE_LENGTH = 80;
    
    int numTestCase;
    
    scanf("%d", &numTestCase);
    
    for (int i = 0; i < numTestCase; i++) {
        char testCase[TESTCASE_LENGTH];
        scanf("%s", testCase);
        
        int totalScore = 0;
        int nextCaseScore = 1;
        for (int j = 0; j < strlen(testCase); j++) {
            if (testCase[j] == 'O') {
                totalScore += nextCaseScore;
                nextCaseScore++;
            } else if (testCase[j] == 'X') {
                nextCaseScore = 1;
            }
        }
        
        printf("%d\n", totalScore);
    }
    

    return 0;
}
