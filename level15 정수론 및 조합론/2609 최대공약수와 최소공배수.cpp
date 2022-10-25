#include <iostream>

int main(void)
{
    int num1;
    int num2;
    
    scanf("%d %d", &num1, &num2);
    
    int greatestCommonFactor = 1;
    int minNum = num1 < num2 ? num1 : num2;
    for (int i = 2; i <= minNum; i++) {
        if (num1 % i != 0 || num2 % i != 0) {
            continue;
        }
        
        greatestCommonFactor = i;
    }
    
    int temp1 = 1;
    int temp2 = 1;
    while (num1 * temp1 != num2 * temp2) {
        if (num1 * temp1 < num2 * temp2) {
            temp1++;
        } else {
            temp2++;
        }
    }
    int leastCommonMultiple = num1 * temp1;
    
    printf("%d\n%d", greatestCommonFactor, leastCommonMultiple);
    
    return 0;
}
