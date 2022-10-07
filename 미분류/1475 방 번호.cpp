#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char input[8];
    int numCount[10];
    
    memset(numCount, 0, sizeof(int) * 10);
    
    scanf("%s", input);
    
    int i = 0;
    while (input[i] != '\0')
    {
        int num = input[i] - '0';
        
        numCount[num]++;
        
        i++;
    }
    
    numCount[6] += numCount[9];
    numCount[9] = 0;
    
    if (numCount[6] % 2 == 0)
    {
        numCount[6] /= 2;
    }
    else
    {
        numCount[6] /= 2;
        numCount[6]++;
    }
    
    int max = -1;
    for (int i = 0; i < 9; i++)
    {
        if (numCount[i] > max)
        {
            max = numCount[i];
        }
    }
    
    printf("%d", max);

    return 0;
}
