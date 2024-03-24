#include <iostream>

int main(void)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int num;
        scanf("%d", &num);
        
        sum += num * num;
    }
    
    printf("%d", sum % 10);
}
