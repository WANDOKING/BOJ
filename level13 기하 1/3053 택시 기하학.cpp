#include <iostream>
#include <cmath>

int main(void)
{
    int r;
    
    scanf("%d", &r);
    
    printf("%.6lf\n", r * r * M_PI);
    printf("%.6lf\n", (r * 2) * (r * 2) / (double) 2);
}
