#include <iostream>

int GetPeopleRecursive(int a, int b)
{
    if (a == 0) {
        return b;
    }
    
    int ret = 0;
    for (int i = 1; i <= b; i++) {
        ret += GetPeopleRecursive(a - 1, i);
    }
    
    return ret;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int k;
        int n;
        
        scanf("%d %d", &k, &n);
        
        printf("%d\n", GetPeopleRecursive(k, n));
    }

    return 0;
}
